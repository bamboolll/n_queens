/*
Eight Queens is a simple toy for experimenting with the 8 or the more
general nxn problem.
Copyright (C) 2009  Mohammad Mehdi Salem Naraghi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solutionsthread.h"
#include "chessboard.h"
#include "solutionsmodel.h"
#include "progresswidget.h"
#include "aboutdialog.h"
#include <unistd.h>
#include <cmath>
#include <QDebug>
#include <QDir>
#include <QStringListModel>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QCloseEvent>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_solutionSavePath(QDir::homePath() + "/solutions.txt")
{
  setupUi(this);

  // Icons
#if QT_VERSION >= 0x040600
  saveSolutionsAct->setIcon(QIcon::fromTheme("document-save-as", QIcon(":/images/document-save-as.png")));
  quitAct->setIcon(QIcon::fromTheme("application-exit"));
  findSolutionAct->setIcon(QIcon::fromTheme("edit-find", QIcon(":/images/edit-find.png")));
  clearBoardAct->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/edit-clear.png")));
  aboutAct->setIcon(QIcon::fromTheme("help-about"));
#endif

  solutionLedsContainer->layout()->setAlignment(Qt::AlignCenter);
  solutionsView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  solutionsView->verticalHeader()->hide();

  connect(saveSolutionsAct, SIGNAL(triggered()), this, SLOT(saveSolutions()));
  connect(showLedsAct, SIGNAL(toggled(bool)), this, SLOT(showSolutionLeds(bool)));

  m_chessBoard = new ChessBoard(boardDimensionSpinBox->value(), this);
  connect(boardDimensionSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setBoardDimension(int)));
  connect(boardDimensionSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateSolutionLeds()));
  chessBoardWidget->setChessBoard(m_chessBoard);
  connect(chessBoardWidget, SIGNAL(toggleQueen(int, int)), this, SLOT(updateSolutionLeds()));
  connect(findSolutionAct, SIGNAL(triggered()), this, SLOT(calculateSolutions()));
  connect(clearBoardAct, SIGNAL(triggered()), m_chessBoard, SLOT(clear()));
  connect(clearBoardAct, SIGNAL(triggered()), this, SLOT(updateSolutionLeds()));
  connect(clearSolutionsAct, SIGNAL(triggered()), this, SLOT(clearSolutions()));
  connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
  connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
  connect(markBlockedFieldsAct, SIGNAL(toggled(bool)), this, SLOT(markBlockedFields(bool)));

  m_solutionsModel = new SolutionsModel(this);
  m_solutionsModel->setDimension(boardDimensionSpinBox->value());
  solutionsView->setModel(m_solutionsModel);
  connect(m_solutionsModel, SIGNAL(numberOfSolutionsChanged(int)),
          this, SLOT(updateNumberOfSolutions(int)));
  connect(solutionsView, SIGNAL(clicked(const QModelIndex&)),
          this, SLOT(solutionClicked(const QModelIndex&)));

  m_solutionsThread = new SolutionsThread(m_solutionsModel);
  connect(m_solutionsThread, SIGNAL(started()),
          this, SLOT(onThreadStatusChanged()));
  connect(m_solutionsThread, SIGNAL(finished()),
          this, SLOT(onThreadStatusChanged()));
  connect(m_solutionsThread, SIGNAL(terminated()),
          this, SLOT(onThreadStatusChanged()));

  m_progressWidget = new ProgressWidget;
  statusbar->addPermanentWidget(m_progressWidget);
  m_progressWidget->hide();
  connect(m_progressWidget, SIGNAL(abortThreadOperation()),
          m_solutionsThread, SLOT(abort()));
  connect(m_solutionsThread, SIGNAL(progressChanged(int)),
          m_progressWidget, SLOT(updateProgress(int)));

  m_numberOfSolutionsLabel = new QLabel;
  statusbar->addPermanentWidget(m_numberOfSolutionsLabel);
  updateNumberOfSolutions(0);

  saveSolutionsAct->setEnabled(false);
  readSettings();

}

MainWindow::~MainWindow()
{
  m_solutionsThread->terminate();
  m_solutionsThread->deleteLater();
}

void MainWindow::changeEvent(QEvent* e)
{
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:;
      retranslateUi(this);
      break;
    default:
      break;
  }
}

void MainWindow::closeEvent(QCloseEvent* e)
{
  // HACK. Without this quitting the app takes an eternity when a lot of solutions have been found
  m_solutionsModel->clear();

  writeSettings();
  e->accept();
}

void MainWindow::calculateSolutions()
{
  clearSolutions();
  m_solutionsThread->setDimension(boardDimensionSpinBox->value());
  m_solutionsThread->start();
}

void MainWindow::solutionClicked(const QModelIndex& index)
{
  QString solution = index.data(Qt::UserRole).toString();
  m_chessBoard->clear();
  QStringList l = solution.split(':');
  for (int i = 0; i < m_chessBoard->dimension(); ++i) {
    m_chessBoard->setQueen(i, l.at(i).toInt());
  }
  updateSolutionLeds();
}

void MainWindow::setBoardDimension(int dimension)
{
  m_solutionsModel->clear();
  m_solutionsModel->setDimension(dimension);
  m_chessBoard->setDimension(dimension);
}

void MainWindow::about()
{
  static AboutDialog* dlg = new AboutDialog(this);
  dlg->show();
  dlg->raise();
  dlg->activateWindow();
}

void MainWindow::clearSolutions()
{
  m_solutionsModel->clear();
  saveSolutionsAct->setEnabled(false);
}

void MainWindow::updateNumberOfSolutions(int numberOfSolutions)
{
  m_numberOfSolutionsLabel->setText(tr("Solutions: ") + QString::number(numberOfSolutions));
}

void MainWindow::markBlockedFields(bool enable)
{
  chessBoardWidget->setMarkBlockedFieldsEnabled(enable);
}

void MainWindow::onThreadStatusChanged()
{
  if (m_solutionsThread->isRunning()) {
    boardDimensionSpinBox->setEnabled(false);
    saveSolutionsAct->setEnabled(false);
    m_progressWidget->show();
  }
  else { // must be finished or terminated
    m_progressWidget->updateProgress(0);
    boardDimensionSpinBox->setEnabled(true);
    m_progressWidget->hide();
    saveSolutionsAct->setEnabled(true);
  }
}

void MainWindow::saveSolutions()
{
  QString path = QFileDialog::getSaveFileName(this,
                                              tr("Save file as"),
                                              m_solutionSavePath,
                                              tr("Text file (*.txt)"));
  if (path.isEmpty())
    return;

  m_solutionSavePath = path;

  if (!(m_solutionsModel->saveSolutions(m_solutionSavePath))) {
    QMessageBox::warning(this,
                         tr("Warning"),
                         tr("Failed to write file."));
  }
}

void MainWindow::updateSolutionLeds()
{
  solutionLeds->setState(m_chessBoard->state());
}

void MainWindow::showSolutionLeds(bool visible)
{
  solutionLedsContainer->setVisible(visible);
}

void MainWindow::readSettings()
{
  QSettings settings;
  showLedsAct->setChecked(settings.value("mainwindow/solutionledsvisible", true).toBool());
  m_solutionSavePath = settings.value("mainwindow/solutionsavepath", m_solutionSavePath).toString();
  QRect geometry = settings.value("mainwindow/geometry", QRect()).toRect();
  if (geometry != QRect())
    setGeometry(geometry);
  restoreState(settings.value("mainwindow/state").toByteArray());
  markBlockedFieldsAct->setChecked(settings.value("board/markblockedfileds", true).toBool());
  boardDimensionSpinBox->setValue(settings.value("board/boarddimensions", 8).toInt());
}

void MainWindow::writeSettings()
{
  QSettings settings;
  settings.setValue("mainwindow/solutionledsvisible", showLedsAct->isChecked());
  settings.setValue("mainwindow/solutionsavepath", m_solutionSavePath);
  settings.setValue("mainwindow/geometry", geometry());
  settings.setValue("mainwindow/state", saveState());
  settings.setValue("board/markblockedfileds", markBlockedFieldsAct->isChecked());
  settings.setValue("board/boarddimensions", boardDimensionSpinBox->value());
}

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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class SolutionsModel;
class ProgressWidget;
class QLabel;
class ChessBoard;
class SolutionsThread;
class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  virtual void changeEvent(QEvent*);
  virtual void closeEvent(QCloseEvent*);

private:
  ChessBoard* m_chessBoard;
  SolutionsModel* m_solutionsModel;
  SolutionsThread* m_solutionsThread;
  QLabel* m_numberOfSolutionsLabel;
  ProgressWidget* m_progressWidget;
  QString m_solutionSavePath;

  void readSettings();
  void writeSettings();

private slots:
  void calculateSolutions();
  void solutionClicked(const QModelIndex&);
  void setBoardDimension(int);
  void about();
  void clearSolutions();
  void updateNumberOfSolutions(int);
  void markBlockedFields(bool);
  void updateSolutionLeds();
  void onThreadStatusChanged();
  void saveSolutions();
  void showSolutionLeds(bool);
};

#endif // MAINWINDOW_H

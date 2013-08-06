/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chessboardwidget.h"
#include "solutionleds.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *quitAct;
    QAction *findSolutionAct;
    QAction *clearSolutionsAct;
    QAction *aboutAct;
    QAction *markBlockedFieldsAct;
    QAction *saveSolutionsAct;
    QAction *clearBoardAct;
    QAction *aboutQtAct;
    QAction *showLedsAct;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    ChessBoardWidget *chessBoardWidget;
    QWidget *solutionLedsContainer;
    QHBoxLayout *horizontalLayout_2;
    SolutionLeds *solutionLeds;
    QMenuBar *menuBar;
    QMenu *menu_Help;
    QMenu *menu_Tools;
    QMenu *menu_File;
    QDockWidget *solutionsDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *solutionsView;
    QDockWidget *boardSettingsDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *boardDimensionSpinBox;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;
    QToolBar *toolsToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        quitAct = new QAction(MainWindow);
        quitAct->setObjectName(QStringLiteral("quitAct"));
        findSolutionAct = new QAction(MainWindow);
        findSolutionAct->setObjectName(QStringLiteral("findSolutionAct"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/edit-find.png"), QSize(), QIcon::Normal, QIcon::Off);
        findSolutionAct->setIcon(icon);
        clearSolutionsAct = new QAction(MainWindow);
        clearSolutionsAct->setObjectName(QStringLiteral("clearSolutionsAct"));
        aboutAct = new QAction(MainWindow);
        aboutAct->setObjectName(QStringLiteral("aboutAct"));
        markBlockedFieldsAct = new QAction(MainWindow);
        markBlockedFieldsAct->setObjectName(QStringLiteral("markBlockedFieldsAct"));
        markBlockedFieldsAct->setCheckable(true);
        markBlockedFieldsAct->setChecked(true);
        saveSolutionsAct = new QAction(MainWindow);
        saveSolutionsAct->setObjectName(QStringLiteral("saveSolutionsAct"));
        clearBoardAct = new QAction(MainWindow);
        clearBoardAct->setObjectName(QStringLiteral("clearBoardAct"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearBoardAct->setIcon(icon1);
        aboutQtAct = new QAction(MainWindow);
        aboutQtAct->setObjectName(QStringLiteral("aboutQtAct"));
        showLedsAct = new QAction(MainWindow);
        showLedsAct->setObjectName(QStringLiteral("showLedsAct"));
        showLedsAct->setCheckable(true);
        showLedsAct->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chessBoardWidget = new ChessBoardWidget(centralWidget);
        chessBoardWidget->setObjectName(QStringLiteral("chessBoardWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(chessBoardWidget->sizePolicy().hasHeightForWidth());
        chessBoardWidget->setSizePolicy(sizePolicy);
        chessBoardWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(chessBoardWidget);

        solutionLedsContainer = new QWidget(centralWidget);
        solutionLedsContainer->setObjectName(QStringLiteral("solutionLedsContainer"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(solutionLedsContainer->sizePolicy().hasHeightForWidth());
        solutionLedsContainer->setSizePolicy(sizePolicy1);
        solutionLedsContainer->setMinimumSize(QSize(0, 10));
        horizontalLayout_2 = new QHBoxLayout(solutionLedsContainer);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        solutionLeds = new SolutionLeds(solutionLedsContainer);
        solutionLeds->setObjectName(QStringLiteral("solutionLeds"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(solutionLeds->sizePolicy().hasHeightForWidth());
        solutionLeds->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(solutionLeds);


        verticalLayout->addWidget(solutionLedsContainer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_Tools = new QMenu(menuBar);
        menu_Tools->setObjectName(QStringLiteral("menu_Tools"));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        solutionsDockWidget = new QDockWidget(MainWindow);
        solutionsDockWidget->setObjectName(QStringLiteral("solutionsDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        solutionsView = new QTableView(dockWidgetContents_2);
        solutionsView->setObjectName(QStringLiteral("solutionsView"));
        solutionsView->setAlternatingRowColors(true);
        solutionsView->setSelectionMode(QAbstractItemView::SingleSelection);
        solutionsView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(solutionsView);

        solutionsDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), solutionsDockWidget);
        boardSettingsDockWidget = new QDockWidget(MainWindow);
        boardSettingsDockWidget->setObjectName(QStringLiteral("boardSettingsDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        boardDimensionSpinBox = new QSpinBox(dockWidgetContents);
        boardDimensionSpinBox->setObjectName(QStringLiteral("boardDimensionSpinBox"));
        boardDimensionSpinBox->setMinimum(1);
        boardDimensionSpinBox->setMaximum(100);
        boardDimensionSpinBox->setValue(8);

        horizontalLayout->addWidget(boardDimensionSpinBox);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        boardSettingsDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), boardSettingsDockWidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolsToolBar = new QToolBar(MainWindow);
        toolsToolBar->setObjectName(QStringLiteral("toolsToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolsToolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Tools->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Help->addAction(aboutAct);
        menu_Help->addAction(aboutQtAct);
        menu_Tools->addAction(findSolutionAct);
        menu_Tools->addAction(clearBoardAct);
        menu_Tools->addAction(clearSolutionsAct);
        menu_Tools->addAction(markBlockedFieldsAct);
        menu_Tools->addAction(showLedsAct);
        menu_File->addAction(saveSolutionsAct);
        menu_File->addSeparator();
        menu_File->addAction(quitAct);
        toolsToolBar->addAction(findSolutionAct);
        toolsToolBar->addAction(clearBoardAct);

        retranslateUi(MainWindow);
        QObject::connect(quitAct, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Eight Queens", 0));
        quitAct->setText(QApplication::translate("MainWindow", "&Quit", 0));
        findSolutionAct->setText(QApplication::translate("MainWindow", "Find &solution", 0));
        findSolutionAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0));
        clearSolutionsAct->setText(QApplication::translate("MainWindow", "&Clear solutions", 0));
        aboutAct->setText(QApplication::translate("MainWindow", "&About", 0));
        aboutAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        markBlockedFieldsAct->setText(QApplication::translate("MainWindow", "Mark &blocked fields", 0));
        markBlockedFieldsAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0));
        saveSolutionsAct->setText(QApplication::translate("MainWindow", "&Save solutions", 0));
        saveSolutionsAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        clearBoardAct->setText(QApplication::translate("MainWindow", "Clear board", 0));
        clearBoardAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0));
        aboutQtAct->setText(QApplication::translate("MainWindow", "About Qt", 0));
        showLedsAct->setText(QApplication::translate("MainWindow", "&Show leds", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menu_Tools->setTitle(QApplication::translate("MainWindow", "&Tools", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        solutionsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Solutions", 0));
        boardSettingsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Board Settings", 0));
        label->setText(QApplication::translate("MainWindow", "Board Dimension", 0));
        toolsToolBar->setWindowTitle(QApplication::translate("MainWindow", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

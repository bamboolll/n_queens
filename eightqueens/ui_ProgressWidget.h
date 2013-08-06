/********************************************************************************
** Form generated from reading ui file 'ProgressWidget.ui'
**
** Created: Mon Feb 1 19:07:26 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROGRESSWIDGET_H
#define UI_PROGRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressWidget
{
public:
  QHBoxLayout *horizontalLayout;
  QLabel *label;
  QProgressBar *progressBar;
  QToolButton *toolButton;
  QToolButton *toolButton_2;

  void setupUi(QWidget *ProgressWidget) {
    if (ProgressWidget->objectName().isEmpty())
      ProgressWidget->setObjectName(QString::fromUtf8("ProgressWidget"));
    ProgressWidget->resize(318, 46);
    horizontalLayout = new QHBoxLayout(ProgressWidget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label = new QLabel(ProgressWidget);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    progressBar = new QProgressBar(ProgressWidget);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setValue(24);

    horizontalLayout->addWidget(progressBar);

    toolButton = new QToolButton(ProgressWidget);
    toolButton->setObjectName(QString::fromUtf8("toolButton"));

    horizontalLayout->addWidget(toolButton);

    toolButton_2 = new QToolButton(ProgressWidget);
    toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

    horizontalLayout->addWidget(toolButton_2);


    retranslateUi(ProgressWidget);

    QMetaObject::connectSlotsByName(ProgressWidget);
  } // setupUi

  void retranslateUi(QWidget *ProgressWidget) {
    ProgressWidget->setWindowTitle(QApplication::translate("ProgressWidget", "Form", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ProgressWidget", "Progress:", 0, QApplication::UnicodeUTF8));
    toolButton->setText(QApplication::translate("ProgressWidget", "...", 0, QApplication::UnicodeUTF8));
    toolButton_2->setText(QApplication::translate("ProgressWidget", "...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ProgressWidget);
  } // retranslateUi

};

namespace Ui
{
class ProgressWidget: public Ui_ProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSWIDGET_H

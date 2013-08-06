/********************************************************************************
** Form generated from reading UI file 'progresswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSWIDGET_H
#define UI_PROGRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QToolButton *abortToolButton;

    void setupUi(QWidget *ProgressWidget)
    {
        if (ProgressWidget->objectName().isEmpty())
            ProgressWidget->setObjectName(QStringLiteral("ProgressWidget"));
        ProgressWidget->resize(275, 35);
        horizontalLayout = new QHBoxLayout(ProgressWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ProgressWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(ProgressWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        abortToolButton = new QToolButton(ProgressWidget);
        abortToolButton->setObjectName(QStringLiteral("abortToolButton"));

        horizontalLayout->addWidget(abortToolButton);


        retranslateUi(ProgressWidget);

        QMetaObject::connectSlotsByName(ProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *ProgressWidget)
    {
        ProgressWidget->setWindowTitle(QApplication::translate("ProgressWidget", "Form", 0));
        label->setText(QApplication::translate("ProgressWidget", "Progress:", 0));
#ifndef QT_NO_TOOLTIP
        abortToolButton->setToolTip(QApplication::translate("ProgressWidget", "Abort the search for solutions.", 0));
#endif // QT_NO_TOOLTIP
        abortToolButton->setText(QApplication::translate("ProgressWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressWidget: public Ui_ProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSWIDGET_H

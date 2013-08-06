#include "progresswidget.h"
#include "ui_ProgressWidget.h"

ProgressWidget::ProgressWidget(QWidget *parent)
    : QWidget(parent)
{
  setupUi(this);
  abortToolButton->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
  connect(abortToolButton, SIGNAL(released()), this, SIGNAL(abortThreadOperation()));
}

ProgressWidget::~ProgressWidget()
{
}

void ProgressWidget::changeEvent(QEvent *e)
{
  QWidget::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      retranslateUi(this);
      break;
    default:
      break;
  }
}

void ProgressWidget::updateProgress(int progress)
{
  progressBar->setValue(progress);
}


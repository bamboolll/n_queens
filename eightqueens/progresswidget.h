#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>
#include "ui_progresswidget.h"

class ProgressWidget : public QWidget, public Ui::ProgressWidget
{
  Q_OBJECT
public:
  ProgressWidget(QWidget *parent = 0);
  ~ProgressWidget();

public slots:
  void updateProgress(int);

signals:
  void abortThreadOperation();

protected:
  void changeEvent(QEvent *e);
};

#endif // PROGRESSWIDGET_H

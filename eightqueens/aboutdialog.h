#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "ui_aboutdialog.h"

class AboutDialog : public QDialog, public Ui::AboutDialog
{
  Q_OBJECT
public:
  AboutDialog(QWidget* parent = 0);
  ~AboutDialog();

protected:
  void changeEvent(QEvent*);

};

#endif // ABOUTDIALOG_H

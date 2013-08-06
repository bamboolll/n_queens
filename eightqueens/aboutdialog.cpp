#include "aboutdialog.h"
#include <QFile>

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent)
{
  setupUi(this);
  QFile f(":COPYING");
  if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    licenseBrowser->setText(f.readAll());
  }

}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::changeEvent(QEvent* e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      retranslateUi(this);
      break;
    default:
      break;
  }
}

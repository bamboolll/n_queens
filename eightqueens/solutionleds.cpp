#include "solutionleds.h"
#include "qled.h"
#include <QHBoxLayout>
#include <QDebug>

SolutionLeds::SolutionLeds(QWidget* parent)
    : QWidget(parent)
{
  m_redLed = new QLed;
  m_redLed->setOnColor(QLed::Red);

  m_yellowLed = new QLed;
  m_yellowLed->setOnColor(QLed::Yellow);

  m_greenLed = new QLed;
  m_greenLed->setOnColor(QLed::Green);

  QHBoxLayout* lo = new QHBoxLayout;
  lo->addWidget(m_redLed);
  lo->addWidget(m_yellowLed);
  lo->addWidget(m_greenLed);

  setLayout(lo);
}

void SolutionLeds::setState(const ChessBoard::State& state)
{
  switch (state) {
    case ChessBoard::Cleared:
      m_redLed->setValue(false);
      m_yellowLed->setValue(false);
      m_greenLed->setValue(false);
      break;
    case ChessBoard::Invalid:
      m_redLed->setValue(true);
      m_yellowLed->setValue(false);
      m_greenLed->setValue(false);
      break;
    case ChessBoard::Intermediate:
      m_redLed->setValue(false);
      m_yellowLed->setValue(true);
      m_greenLed->setValue(false);
      break;
    case ChessBoard::Valid:
      m_redLed->setValue(false);
      m_yellowLed->setValue(false);
      m_greenLed->setValue(true);
      break;
  }
}

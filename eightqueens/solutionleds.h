#ifndef SOLUTIONLEDS_H
#define SOLUTIONLEDS_H

#include <QWidget>
#include "chessboard.h"

class QLed;
class SolutionLeds : public QWidget
{
  Q_OBJECT
public:
  SolutionLeds(QWidget* parent = 0);
  void setState(const ChessBoard::State& state);
private:
  QLed* m_greenLed;
  QLed* m_yellowLed;
  QLed* m_redLed;
};

#endif // SOLUTIONLEDS_H

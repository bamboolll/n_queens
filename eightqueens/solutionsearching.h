#ifndef SOLUTIONSEARCHING_H
#define SOLUTIONSEARCHING_H
#include <QThread>
#include <QStack>
#include <QByteArray>
#include <QList>

class ChessBoard;
class SolutionsSearching: public QObject
{
  Q_OBJECT
public:
  enum Algorithm { Simple = 0,  Steppest = 1 };
  SolutionsSearching(int dimension);
  void setDimension(int);
  void reset();
  void setAlgorithm(Algorithm);
  ChessBoard* findNextMove();


public slots:
signals:

private:
  ChessBoard* chessBoard;
  int m_algorithm;
  int m_dimension;

  int calculateH(ChessBoard* chessBoard);
  ChessBoard* findNextMove_Simple();
  ChessBoard* findNextMove_Steppest();
  int getQueenAtRow(int);
  bool checkAttackable(int, int, int, int);
};
#endif // SOLUTIONSEARCHING_H

#ifndef SOLUTIONSTHREAD_H
#define SOLUTIONSTHREAD_H

#include <QThread>
#include <QStack>
#include <QByteArray>
#include <QList>

class SolutionsModel;
class ChessBoard;
class SolutionsThread : public QThread
{
  Q_OBJECT
public:
  SolutionsThread(SolutionsModel*);
  void setDimension(int);
  void run();
  void findSolution(ChessBoard* chessBoard, int row);

public slots:
  void abort();

signals:
  void progressChanged(int);

private:
  SolutionsModel* m_solutionsModel;
  int m_dimension;
  const int BUFFER_MAX;
  QList<QByteArray> m_solutionsBuffer;
  int m_progress;

  volatile bool abortCondition;
  QStack<int> m_currentProgress;
  void calculateProgress();

  void storeSolution(ChessBoard* chessBoard);
  void cleanUp();
  void flushBuffer();
};

#endif // SOLUTIONSTHREAD_H

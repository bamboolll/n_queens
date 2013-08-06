#include "solutionsthread.h"
#include "solutionsmodel.h"
#include "chessboard.h"
#include <cmath>
#include <QDebug>

SolutionsThread::SolutionsThread(SolutionsModel* model)
    : m_solutionsModel(model)
    , m_dimension(0)
    , BUFFER_MAX(500)
{
}

void SolutionsThread::setDimension(int dimension)
{
  m_dimension = dimension;
}

void SolutionsThread::run()
{
  cleanUp();
  ChessBoard chessBoard(m_dimension);
  m_solutionsModel->clear();
  m_solutionsModel->setDimension(m_dimension);
  findSolution(&chessBoard, 0);
  flushBuffer();
  cleanUp();
}

void SolutionsThread::findSolution(ChessBoard* chessBoard, int row)
{
  if (abortCondition)
    return;

  if (row >= chessBoard->dimension()) {
    storeSolution(chessBoard);
  }
  else {
    for (int column = 0; column < chessBoard->dimension(); ++column) {
      if (abortCondition)
        return;
      if (chessBoard->at(row, column) == ChessBoard::Available) {
        chessBoard->setQueen(row, column);
        m_currentProgress.push(column);
        calculateProgress();
        findSolution(chessBoard, row + 1);
        chessBoard->unsetQueen(row, column);
        m_currentProgress.pop();
        calculateProgress();
      }
    }
  }
}

void SolutionsThread::calculateProgress()
{
  qreal p = 0;
  for (int i = 0; i < m_currentProgress.size(); ++i) {
    p += m_currentProgress[i] * (100.0 / pow(m_dimension, i + 1));
  }
  if ((int) p > m_progress) {
    m_progress = p;
    emit progressChanged(m_progress);
  }
}

void SolutionsThread::storeSolution(ChessBoard* chessBoard)
{
  int dimension = chessBoard->dimension();
  QByteArray solution(dimension, 0);
  for (int i = 0; i < dimension; ++i) {
    for (int j = 0; j < dimension; ++j) {
      if (chessBoard->at(i, j) == ChessBoard::Queen) {
        solution[i] = j;
        break;
      }
    }
  }

  m_solutionsBuffer << solution;

  if (m_solutionsBuffer.size() >= BUFFER_MAX) {
    flushBuffer();
  }
}

void SolutionsThread::abort()
{
  abortCondition = true;
}

void SolutionsThread::cleanUp()
{
  m_progress = 0;
  m_currentProgress.clear();
  abortCondition = false;
}

void SolutionsThread::flushBuffer()
{
  if (m_solutionsBuffer.size() > 0) {
    m_solutionsModel->addSolutions(m_solutionsBuffer);
    m_solutionsBuffer.clear();
  }
}

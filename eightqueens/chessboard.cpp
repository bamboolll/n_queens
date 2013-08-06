/*
Eight Queens is a simple toy for experimenting with the 8 or the more
general nxn problem.
Copyright (C) 2009  Mohammad Mehdi Salem Naraghi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "chessboard.h"
#include <QDebug>

ChessBoard::ChessBoard(int dimension, QObject* parent)
    : QObject(parent)
{
  setDimension(dimension);
}

ChessBoard::Availability ChessBoard::at(int row, int column) const
{
  int state = board[row][column];

  if (state == 0)
    return Available;
  else if (state > 0)
    return Unavailable;
  else
    return Queen;
}

int ChessBoard::valueAt(int row, int column) const
{
  return board[row][column];
}


void ChessBoard::setQueen(int row, int column)
{
  if (board[row][column] == Available)
    updateAvailability(row, column, ChessBoard::SetQueen);
}

void ChessBoard::unsetQueen(int row, int column)
{
  if (board[row][column] == Queen)
    updateAvailability(row, column, ChessBoard::UnsetQueen);
}

void ChessBoard::updateAvailability(int row, int column, Action action)
{
// horizontally and vertically
  for (int i = 0; i < m_dimension; ++i) {    
    (action == SetQueen) ? ++board[row][i]    : --board[row][i];
    (action == SetQueen) ? ++board[i][column] : --board[i][column];
  }


  // diagonal entries
  int min, r, c;

  //  descending
  r = row;
  c = column;
  min = qMin(r, c);
  r -= min;
  c -= min;

  while (qMax(r, c) < m_dimension) {
    (action == SetQueen) ?  ++board[r][c] : --board[r][c];
    ++r;
    ++c;
  }

  // ascending
  r = row;
  c = column;
  min = qMin(c, m_dimension - 1 - r);
  r += min;
  c -= min;

  while (qMax(c, m_dimension - 1 - r) < m_dimension) {
    (action == SetQueen) ? ++board[c][r] : --board[c][r];
    --r;
    ++c;
  }

  // restore overwritten queen
  (action == SetQueen) ? board[row][column] = Queen : board[row][column] = Available;

  emit updateViews();
}

void ChessBoard::toggleQueen(int row, int column)
{
  board[row][column] == Queen ? unsetQueen(row, column) : setQueen(row, column);
}

int ChessBoard::dimension() const
{
  return m_dimension;
}

void ChessBoard::clear()
{
  for (int i = 0; i < m_dimension; ++i)
    for (int j = 0; j < m_dimension; ++j)
      board[i][j] = Available;

  emit updateViews();
}

void ChessBoard::setDimension(int dimension)
{
  if (dimension == m_dimension)
    return;

  m_dimension = 0;
  board.clear();

  for (int i = 0; i < dimension; ++i) {
    QList<int> l;
    for (int j = 0; j < dimension; ++j)
      l << Available;
    board << l;
  }
  m_dimension = dimension;
  emit dimensionChanged(dimension);
  emit updateViews();
}

ChessBoard::State ChessBoard::state() const
{
  // if the number of queens == dimension, then state is valid
  quint8 queens = 0;
  int clearFields = 0;
  for (int i = 0; i < m_dimension; ++i) {
    int rowFields = 0;
    int colFields = 0;
    for (int j = 0; j < m_dimension; ++j) {
      if (board[i][j] == Queen)
        ++queens;

      if (board[i][j] == Available)
        ++clearFields;

      if (board[i][j] >= Unavailable)
        ++rowFields;

      if (board[j][i] >= Unavailable)
        ++colFields;
    }

    if (rowFields == m_dimension || colFields == m_dimension)
      return ChessBoard::Invalid;
  }

  if (queens == m_dimension)
    return ChessBoard::Valid;

  if (clearFields == (m_dimension * m_dimension))
    return ChessBoard::Cleared;

  return ChessBoard::Intermediate;

}

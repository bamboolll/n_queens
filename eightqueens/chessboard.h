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

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QList>
#include <QObject>

class ChessBoard : public QObject
{
  Q_OBJECT
public:
  ChessBoard(int dimension, QObject* parent = 0);
  enum Availability { Queen = -1,  Available = 0, Unavailable = 1 };
  enum Action { SetQueen = 0, UnsetQueen };
  enum State { Cleared, Invalid, Intermediate, Valid };
  Availability at(int, int) const;
  int valueAt(int, int) const;
  void setQueen(int, int);
  void unsetQueen(int, int);
  int dimension() const;
  void setDimension(int);
  State state() const;
public slots:
  void toggleQueen(int, int);
  void clear();
signals:
  void updateViews();
  void dimensionChanged(int);
private:
  QList<QList<int> > board;

  void updateAvailability(int, int, Action);
  int m_dimension;

};

#endif

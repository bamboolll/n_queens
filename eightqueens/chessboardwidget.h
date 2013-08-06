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

#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>
#include <QList>
#include <QRectF>
#include <QPixmap>

class QSvgRenderer;
class ChessBoard;
class ChessBoardWidget : public QWidget
{
  Q_OBJECT
public:
  ChessBoardWidget(QWidget* parent = 0);
  void setChessBoard(ChessBoard*);
  void setMarkBlockedFieldsEnabled(bool);
  bool isMarkBlockedFiledsEnabled() const;
protected:
  void paintEvent(QPaintEvent*);
  void resizeEvent(QResizeEvent*);
  void mousePressEvent(QMouseEvent*);
signals:
  void toggleQueen(int, int);
private:
  QList<QChar> m_alphabet;
  qreal m_rectSide;
  QSvgRenderer* m_renderer;
  QPixmap m_queenBlackPixmap;
  QPixmap m_queenWhitePixmap;
  QPixmap m_crossPixmap;
  QPixmap m_chessBoardPixmap;
  ChessBoard* m_chessBoard;
  bool m_markUnavailableFields;
private slots:
  void updatePixmaps();


};

#endif // CHESSBOARDWIDGET_H

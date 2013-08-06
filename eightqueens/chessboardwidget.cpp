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

#include "chessboardwidget.h"
#include "chessboard.h"
#include "usefulfunctions.h"

#include <QPainter>
#include <QDebug>
#include <QSvgRenderer>
#include <QMouseEvent>
#include <QStyleOption>

ChessBoardWidget::ChessBoardWidget(QWidget* parent)
    : QWidget(parent)
    , m_chessBoard(0)
    , m_markUnavailableFields(true)
{
  m_renderer = new QSvgRenderer(this);
  // to be later used with getLabelFromInts
  for (int i = 0; i < 26; ++i)
    m_alphabet << QChar('a' + i);
}


void ChessBoardWidget::mousePressEvent(QMouseEvent* event)
{
  QRect targetRect = m_chessBoardPixmap.rect();
  targetRect.moveCenter(rect().center());
  int xoffset = targetRect.left();
  int yoffset = targetRect.top();

  const int sideCount = m_chessBoard->dimension();
  if (m_chessBoard) {
    QPoint pos = event->pos();
    int row = int((pos.y() - yoffset) / m_rectSide) - 1;
    int col = int((pos.x() - xoffset) / m_rectSide) - 1;
    if (row >= 0 && row < sideCount && col >= 0 && col < sideCount)
      emit toggleQueen(col, row);
  }

  QWidget::mousePressEvent(event);
}

void ChessBoardWidget::paintEvent(QPaintEvent* event)
{
  Q_UNUSED(event);

  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

  if (!m_chessBoard)
    return;

  // draw board
  QRect targetRect = m_chessBoardPixmap.rect();
  targetRect.moveCenter(rect().center());
  p.drawPixmap(targetRect, m_chessBoardPixmap, m_chessBoardPixmap.rect());

  const int sideCount = m_chessBoard->dimension();

  for (int i = 0; i < sideCount * sideCount; ++i) {
    int row = i / sideCount;
    int col = i % sideCount;
    int xoffset = targetRect.left();
    int yoffset = targetRect.top();
    QRectF fieldRect(xoffset + (row + 1) * m_rectSide,
                     yoffset + (col + 1) * m_rectSide, m_rectSide, m_rectSide);

    bool hasQueen = m_chessBoard->at(row, col) == ChessBoard::Queen;
    bool hasCross = (m_chessBoard->at(row, col) == ChessBoard::Unavailable) && m_markUnavailableFields;

    if (hasQueen) {
      if ((row % 2 == 0 && col % 2 == 0) || (row % 2 != 0 && col % 2 != 0)) // white field
        p.drawPixmap(fieldRect.toRect(), m_queenBlackPixmap);
      else // black field
        p.drawPixmap(fieldRect.toRect(), m_queenWhitePixmap);
    }
    else if (hasCross) {
      //p.setPen(Qt::red); // DEBUG remove me later
      //p.drawText(fieldRect.toRect(), Qt::AlignCenter, QString::number(m_chessBoard->valueAt(row, col))); // DEBUG remove me later
      p.drawPixmap(fieldRect.toRect(), m_crossPixmap);
    }

  }
}

void ChessBoardWidget::resizeEvent(QResizeEvent* event)
{
  Q_UNUSED(event);

  if (m_chessBoard)
    updatePixmaps();
}

void ChessBoardWidget::setChessBoard(ChessBoard* chessBoard)
{
  if (m_chessBoard) {
    m_chessBoard->disconnect(this);
    disconnect(m_chessBoard);
  }

  m_chessBoard = chessBoard;
  if (chessBoard) {
    updatePixmaps();
    connect(this, SIGNAL(toggleQueen(int, int)), chessBoard, SLOT(toggleQueen(int, int)));
    connect(chessBoard, SIGNAL(dimensionChanged(int)), this, SLOT(updatePixmaps()));
    connect(chessBoard, SIGNAL(updateViews()), this, SLOT(update()));
  }
  update();
}

void ChessBoardWidget::setMarkBlockedFieldsEnabled(bool enable)
{
  if (enable == m_markUnavailableFields)
    return;

  m_markUnavailableFields = enable;
  update();
}

bool ChessBoardWidget::isMarkBlockedFiledsEnabled() const
{
  return m_markUnavailableFields;
}

void ChessBoardWidget::updatePixmaps()
{
  QRectF cr = contentsRect();
  const qreal side = qMin(cr.width(), cr.height());
  cr = QRectF(0, 0, side, side);
  const int sideCount = m_chessBoard->dimension();
  qreal rectSide = cr.width() / (sideCount + 2);
  m_rectSide = rectSide;

  // create black queen pixmaps
  QStyleOption opt;
  opt.init(this);
  QPainter p;
  QRectF imageRect(0.0, 0.0, rectSide, rectSide);
  qreal offset = rectSide * 0.1;
  imageRect.adjust(offset, offset, -offset, -offset);

  m_queenBlackPixmap = QPixmap(rectSide , rectSide);
  m_queenBlackPixmap.fill(Qt::transparent);
  m_renderer->load(QString(":/images/queen_black.svg"));
  p.begin(&m_queenBlackPixmap);
  m_renderer->render(&p, imageRect);
  p.end();

  // create white queen pixmap
  m_queenWhitePixmap = QPixmap(rectSide , rectSide);
  m_queenWhitePixmap.fill(Qt::transparent);
  m_renderer->load(QString(":/images/queen_white.svg"));
  p.begin(&m_queenWhitePixmap);
  m_renderer->render(&p, imageRect);
  p.end();

  // create cross pixmap
  m_crossPixmap = QPixmap(rectSide, rectSide);
  m_crossPixmap.fill(Qt::transparent);
  m_renderer->load(QString(":/images/cross.svg"));
  p.begin(&m_crossPixmap);
  m_renderer->render(&p, imageRect);
  p.end();

  // create board pixmap
  m_chessBoardPixmap = QPixmap(rectSide * (sideCount + 2), rectSide * (sideCount + 2));
  m_chessBoardPixmap.fill(Qt::transparent);
  p.begin(&m_chessBoardPixmap);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

  // draw alphabets and digits
  p.save();
  QFont f = font();
  f.setWeight(QFont::Bold);
  f.setPixelSize(rectSide * 0.6);
  p.setFont(f);
  p.setPen(palette().dark().color());

  for (int i = 1; i <= sideCount; ++i) {
    QString label = getLabelFromInt(i - 1, m_alphabet);
    p.drawText(QRectF(cr.left() + i * rectSide, cr.top(), rectSide, rectSide),
               Qt::AlignCenter, label);
    p.drawText(QRectF(cr.left() + i * rectSide, cr.bottom() - rectSide, rectSide, rectSide),
               Qt::AlignCenter, label);
    p.drawText(QRectF(cr.left(), cr.bottom() - (i + 1) * rectSide, rectSide, rectSide),
               Qt::AlignCenter, QString::number(i));
    p.drawText(QRectF(cr.right() - rectSide, cr.bottom() - (i + 1) * rectSide, rectSide, rectSide),
               Qt::AlignCenter, QString::number(i));
  }
  p.restore();

  // draw fields
  p.setBrush(Qt::black);
  p.drawRect(cr.adjusted(rectSide, rectSide, -rectSide, -rectSide));
  p.setBrush(Qt::white);
  for (int i = 0; i < sideCount * sideCount; ++i) {
    int row = i / sideCount;
    int col = i % sideCount;
    if ((row % 2 == 0 && col % 2 == 0) || (row % 2 != 0 && col % 2 != 0)) {
      QRectF fieldRect((row + 1) * rectSide, (col + 1) * rectSide, rectSide, rectSide);
      p.drawRect(fieldRect);
    }
  }
  p.end();
}

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

#ifndef SOLUTIONSMODEL_H
#define SOLUTIONSMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QList>
#include <QByteArray>

class SolutionsModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  SolutionsModel(QObject* parent = 0);
  virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
  void addSolutions(const QList<QByteArray>&);
  void setDimension(int);

public slots:
  void clear();
  bool saveSolutions(const QString&) const;

signals:
  void numberOfSolutionsChanged(int);

private:
  QList<QByteArray> m_solutions;
  mutable QList<QList<bool> > m_matrix;
  int m_dimension;
  QList<QChar> m_alphabet;
  void clearMatrix() const;
  QByteArray transpone(const QByteArray&) const;
  QString solutionToString(const QByteArray&, const QString& delimiter = QString("  ")) const;
};

#endif // SOLUTIONSMODEL_H

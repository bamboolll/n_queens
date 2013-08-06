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

#include "solutionsmodel.h"
#include "usefulfunctions.h"
#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>

SolutionsModel::SolutionsModel(QObject* parent)
    : QAbstractTableModel(parent)
    , m_dimension(0)
{
  // to be later used with getLabelFromInts
  for (int i = 0; i < 26; ++i)
    m_alphabet << QChar('a' + i);
}

int SolutionsModel::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return m_solutions.size();
}

int SolutionsModel::columnCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return m_dimension;
}

QVariant SolutionsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
    return getLabelFromInt(section, m_alphabet);
  }

  return QAbstractTableModel::headerData(section, orientation, role);
}

QVariant SolutionsModel::data(const QModelIndex & index, int role) const
{
  if (index.isValid()) {

    if (role == Qt::TextAlignmentRole) {
      return Qt::AlignCenter;
    }

    if (role == Qt::DisplayRole) {
      return int(transpone(m_solutions.at(index.row())).at(index.column()) + 1);
    }

    if (role == Qt::UserRole) {
      QStringList l;
      QByteArray ba = m_solutions.at(index.row());
      for (int i = 0; i < ba.size(); ++i)
        l << QString::number(int(ba.at(i)));
      return l.join(":");
    }

  }
  return QVariant();
}

void SolutionsModel::addSolutions(const QList<QByteArray>& solutions)
{
  beginInsertRows(QModelIndex(), m_solutions.size(), m_solutions.size() + solutions.size() - 1);
  m_solutions.append(solutions);
  endInsertRows();
  emit numberOfSolutionsChanged(m_solutions.size());
  QCoreApplication::processEvents();
}

QByteArray SolutionsModel::transpone(const QByteArray& ba) const
{
  clearMatrix();

  // set queens
  for (int i = 0; i < ba.size(); ++i)
    m_matrix[i][int(ba.at(i))] = true;

  // transpone matrix
  for (int i = 0; i < m_matrix.size() - 1; ++i) {
    for (int j = i + 1; j < m_matrix.size(); ++j) {
      int hilf = m_matrix[i][j];
      m_matrix[i][j] = m_matrix[j][i];
      m_matrix[j][i] = hilf;
    }
  }

  QByteArray result;
  for (int i = 0; i < m_matrix.size(); ++i) {
    for (int j = 0; j < m_matrix.size(); ++j) {
      if (m_matrix[i][j]) {
        result.append(j);
      }
    }
  }

  return result;
}

void SolutionsModel::clearMatrix() const
{
  for (int i = 0; i < m_matrix.size(); ++i)
    for (int j = 0; j < m_matrix.size(); ++j)
      m_matrix[i][j] = false;
}

void SolutionsModel::setDimension(int dimension)
{
  m_dimension = dimension;
  m_matrix.clear();
  // create transponation matrix
  for (int i = 0; i < dimension; ++i) {
    QList<bool> l;
    for (int j = 0; j < dimension; ++j)
      l << false;
    m_matrix << l;
  }
}

void SolutionsModel::clear()
{
#if QT_VERSION >= 0x040600
  beginResetModel();
  m_solutions.clear();
  endResetModel();
#else
  m_solutions.clear();
  reset();
#endif
  emit numberOfSolutionsChanged(0);
}

bool SolutionsModel::saveSolutions(const QString& path) const
{
  QFile file(path);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return false;

  QTextStream out(&file);
  for (int i = 0; i < m_solutions.size(); ++i)
    out << solutionToString(m_solutions.at(i), ",") << "\n";
  file.close();

  return true;
}

QString SolutionsModel::solutionToString(const QByteArray& ba, const QString& delimiter) const
{
  QStringList result;
  for (int i = 0; i < ba.size(); ++i)
    result << QString("%1:%2").arg(getLabelFromInt(i, m_alphabet)).arg(int(ba.at(i)) + 1);
  return result.join(delimiter);
}

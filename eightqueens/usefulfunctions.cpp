#include "usefulfunctions.h"
#include <QList>
#include <cmath>
#include <limits>
using namespace std;

QString getLabelFromInt(int index, const QList<QChar>& alphabet, int base)
{
  // Alphabet should have at least two elements
  if (alphabet.size() < 2)
    return QString();

  if (base < 2 || base > alphabet.size())
    base = alphabet.size();

  double tmp  = log10((index + 1) * (base - 1) + 1) / log10(base);
  // workaround for machine floating point precision issues
  int n = (int)floor(tmp + sqrt(numeric_limits<double>::epsilon()));
  index -= ((pow((double) base, (double) n) - 1) / (base - 1)) - 1;

  QString result(n, alphabet[0]);
  int quotient = index;
  int strIndex = result.length();
  do {
    result[--strIndex] = alphabet[quotient % base];
    quotient = quotient / base;
  }
  while (quotient != 0);

  return result;
}


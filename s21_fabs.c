#include "s21_math.h"
long double s21_fabs(double x) {
  long double res = 0;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG || x == S21_INF_POS)
    res = S21_INF_POS;
  else if (x < 0)
    res = -x;
  else
    res = x;
  return res;
}
#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0;
  if (x == S21_INF_POS || x == S21_INF_NEG)
    result = S21_NAN;
  else if (x != x)
    result = S21_NAN;
  else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
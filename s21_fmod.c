#include "s21_math.h"
long double s21_fmod(double x, double y) {
  long double result = 0.0;
  if (y == 0 && x != 0)
    result = S21_NAN;
  else if (x == 0 && y != 0)
    result = 0;
  else if (x == 0 && y == 0)
    result = S21_NAN;
  else if (x == S21_INF_POS || x == S21_INF_NEG)
    result = S21_NAN;
  else if (y == S21_INF_POS)
    result = (long double)x;
  else {
    long int mod = x / y;
    result = x - (mod * y);
  }
  return result;
}
#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0;
  if (x == S21_INF_POS)
    result = S21_INF_POS;
  else if (x == S21_INF_NEG)
    result = S21_INF_NEG;
  else if (x != x)
    result = S21_NAN;
  else if (x == (long long int)x) {
    result = x;
  } else if (x < 0) {
    result = (long long int)x - 1;
  } else {
    result = (long long int)x;
  }
  return result;
}

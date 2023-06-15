#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0.;
  result = S21_PI / 2 - s21_acos(x);
  return result;
}
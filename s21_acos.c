#include "s21_math.h"
// arccos(x) = pi/2 - arctan(x / sqrt(1 - x^2))

long double s21_acos(double x) {
  long double result = 0.;
  long double y = x / s21_sqrt(1 - s21_pow(x, 2));
  result = S21_PI / 2 - s21_atan(y);
  return result;
}
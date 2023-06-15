#include "s21_math.h"
//Формула Маклорена для арктангенса
// arctan(x) = x - x^3/3 + x^5/5 - x^7/7 + ..
long double s21_atan(double x) {
  long double result = 0.;
  long double term = x;
  long double minus = 1;
  long double i = 1;
  if (x == 0.) {
    result = 0.;
  } else if (x == 1.0) {
    result = S21_PI / 4.0;
  } else if (x == -1.0) {
    result = -S21_PI / 4.0;
  } else if (x != x)
    result = S21_NAN;
  else if (s21_fabs(x) <= 1) {
    while (s21_fabs(term) > 1e-30) {
      result = result + (minus * term) / i;
      i += 2;
      minus *= -1;
      term = term * x * x;
    }
    // arctan(1/x) = pi/2 - arctan(x), если x > 0, и arctan(1/x) = -pi/2 -
    // arctan(x), если x < 0.
  } else if (x < -1) {
    result = -S21_PI / 2 - s21_atan(1 / x);
  } else
    result = S21_PI / 2 - s21_atan(1 / x);
  return result;
}

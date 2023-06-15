#include "s21_math.h"
// sin^2(x) + cos^2(x) = 1

long double s21_sin(double x) {
  long double result = 0;
  int minus = 1;
  if (x == S21_INF_POS || x == S21_INF_NEG)
    result = S21_NAN;
  else if (x != x)
    result = S21_NAN;
  else {
    if (x < 0) minus = -1;
    x = s21_fabs(x);
    x = s21_fmod(x, (2 * S21_PI));
    // проверяем в какой четверти лежит х, чтобы определить знак (не забываем
    // про знак самого х)
    if (x > S21_PI)
      result = -1 * minus * s21_sqrt(1 - s21_pow(s21_cos(x), 2));
    else
      result = minus * s21_sqrt(1 - s21_pow(s21_cos(x), 2));
  }
  return result;
}

#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;
  int minus = 0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    result = 0;
  } else {
    // если степень отрицательная, то результат нужно инвертировать
    if (x < 0) {
      x *= -1;
      minus = 1;
    }
    // ряд Тейлора. e^x = 1 + x/1! + x^2/2! + x^3/3! + ...
    // Переменная ans инициализируется значением result, чтобы начать цикл
    // while. В цикле вычисляется текущее значение ряда Тейлора и добавляется к
    // result. Затем вычисляются значения факториала и степени для следующего
    // члена ряда.
    long double next = 0, xpow = x, fac = 1;
    int n = 1;
    while (s21_fabs(result - next) > 1e-30 || n < 500) {
      next = result;
      result += xpow / fac;
      fac *= ++n;
      xpow *= x;
    }
  }
  // При возведении экспоненты в отрицательную степень нужно 1 делить на число
  // е в заданной степени, но со знаком плюс.
  if (minus) {
    result = 1 / result;
  }
  return result;
}

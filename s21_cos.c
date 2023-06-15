#include "s21_math.h"
/*Квадрат стороны треугольника равен сумме квадратов двух других сторон
минус удвоенное произведение этих сторон на косинус угла между ними.
a^2 = b^2 + c^2 - 2*b*c*cosX

cos принимает х  сразу в радианах
поэтому  используем ряд Тейлора cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... +
(-1)^n*x^(2n)/(2n)!
*/

long double s21_cos(double x) {
  long double result = 1;
  if (x != x || x == S21_INF_POS || x == S21_INF_NEG) {
    result = S21_NAN;
    // } else if (x == S21_INF_POS) {
    //   result = S21_INF_POS;
    // } else if (x == S21_INF_NEG) {
    //   result = 0;
  } else {
    x = s21_fabs(x);
    // вся окружность это 360 градусов или 2π радиан,
    // обрезаем значение x нашего угла до значения в пределах одного оборота
    // окружности.
    x = s21_fmod(x, (2 * S21_PI));
    long double term = 1;
    long double minus = -1;
    long double i = 2, fact = 2;
    // ряды Тейлора. используются только четные производные функции cos(x) (тк
    // косинус это четная функция, он симметричен относительно оси OY)
    while (s21_fabs(term) > 1e-15) {
      term = minus * (s21_pow(x, i) / fact);
      // printf("i = %Lf, fact = %Lf\n", i, fact);
      result += term;
      minus *= -1;
      i += 2;
      fact *= (i - 1) * i;
    }
  }
  return result;
}
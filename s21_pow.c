#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (base != base)
    result = S21_NAN;
  else if (base == 1)
    result = 1;
  else if (base == 0 && exp == 0)
    result = 1;
  else if (base == 0)
    result = 0;
  else if (exp == S21_INF_NEG)
    result = 0;
  else if (exp == S21_INF_POS && base == S21_INF_NEG)
    result = S21_INF_POS;
  else if (exp == 1)
    result = base;
  else {
    // Возведем число base в целую степень, равную целой части exp.
    // Возведем число base в дробную степень. Для этого
    // можно воспользоваться формулой: a^(1/n) = exp(log(a)/n), где n - это
    // знаменатель дробной части exp. Это позволяет нам вычислять корни из
    // чисел, которые не являются целыми степенями. Перемножим результаты
    if (exp > 0) {
      for (long long int i = 0; i < (long long int)exp; i++) {
        result *= base;
      }
    }
    if (exp < 0) {
      for (long long int i = 0; i > (long long int)exp; i--) {
        result /= base;
      }
    }
    long double exp_tail = s21_fabs(exp) - s21_fabs((long long int)exp);

    if (exp > 0 && exp_tail > 0)
      result *= s21_exp(s21_log(base) * exp_tail);
    else if (exp < 0 && exp_tail > 0)
      result *= s21_exp(s21_log(1 / base) * exp_tail);
  }

  return result;
}
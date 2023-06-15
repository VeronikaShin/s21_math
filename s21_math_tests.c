#include <check.h>
#include <math.h>
#define BIGV 1000000000.9
#include "s21_math.h"
//--------------------------s21_ceil---------------------------------

// long double s21_ceil(double x)
// возвращает ближайшее целое число, не меньше заданного значения
START_TEST(test_s21_ceil) {
  for (double i = -5.; i <= 5.; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), S21_EPS);
  }
  ck_assert_ldouble_eq_tol(s21_ceil(BIGV), ceil(BIGV), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-BIGV), ceil(-BIGV), S21_EPS);
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_POS));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_NEG));
}
END_TEST

//--------------------------s21_fabs---------------------------------
// long double s21_fabs(double x)
// вычисляет абсолютное значение числа с плавающей токой
START_TEST(test_s21_fabs) {
  for (double i = -2.; i <= 2.; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), S21_EPS);
  }
  ck_assert_ldouble_eq_tol(s21_ceil(BIGV), ceil(BIGV), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-BIGV), ceil(-BIGV), S21_EPS);
  ck_assert_ldouble_eq_tol(fabs(0.0), s21_fabs(0.0), S21_EPS);
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_eq(s21_fabs(S21_INF_POS), fabs(S21_INF_POS));
}
END_TEST

//--------------------------s21_fmod---------------------------------

// long double s21_fmod(double x, double y)
// остаток операции деления с плавающей точкой
START_TEST(test_s21_fmod) {
  for (double i = -2.; i <= 2.; i += 0.1) {
    for (double j = -2.; j <= 2.; j += 0.1) {
      ck_assert_ldouble_eq_tol(s21_fmod(i, j), fmod(i, j), S21_EPS);
    }
  }
  ck_assert_ldouble_eq_tol(s21_fmod(1e+10, 9), fmod(1e+10, 9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1e+15, 9), fmod(1e+15, 9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 1), fmod(0, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1, S21_INF_POS), fmod(1, S21_INF_POS),
                           S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, S21_INF_POS));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, S21_INF_NEG));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, S21_NAN));
  ck_assert_ldouble_nan(fmod(S21_INF_NEG, S21_INF_POS));
  ck_assert_ldouble_nan(fmod(S21_INF_NEG, S21_INF_NEG));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, S21_INF_POS));
  ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, S21_INF_NEG));
  ck_assert_ldouble_nan(s21_fmod(2.5, 0));
  ck_assert_ldouble_nan(s21_fmod(0, 0));
}
END_TEST

//--------------------------s21_exp---------------------------------

// long double s21_exp(double x)
// возвращает значение e, возведенное в заданную степень
START_TEST(test_s21_exp) {
  for (double i = -2.; i <= 2.; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), S21_EPS);
  }

  ck_assert_ldouble_eq(s21_exp(BIGV), exp(BIGV));
  ck_assert_ldouble_eq_tol(s21_exp(-BIGV), exp(-BIGV), S21_EPS);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq(s21_exp(S21_INF_POS), exp(S21_INF_POS));
  ck_assert_ldouble_eq(s21_exp(S21_INF_NEG), exp(S21_INF_NEG));
}
END_TEST

//--------------------------s21_log---------------------------------

// long double s21_log(double x)
// вычисляет натуральный логарифм
START_TEST(test_s21_log) {
  for (double i = 0.1; i <= 5.; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_eq_tol(s21_log(BIGV), log(BIGV), S21_EPS);
  ck_assert_ldouble_eq(s21_log(S21_INF_POS), log(S21_INF_POS));
  ck_assert_ldouble_nan(s21_log(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
}
END_TEST

//--------------------------s21_atan---------------------------------
START_TEST(test_s21_atan) {
  // testing values for s21_atan [-10 ; 10] with step 0.5
  for (double i = -10; i <= 10; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), S21_EPS);
  }
  // testing NAN for s21_atan
  ck_assert_ldouble_nan(s21_atan(S21_NAN));

  // testing INF for s21_atan
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF_POS), atan(S21_INF_POS), S21_EPS);

  // testing DOUBLE_MAX and DOUBLE_MIN for s21_atan
  ck_assert_ldouble_eq_tol(s21_atan(1.7 * pow(10, 308)),
                           atan(1.7 * pow(10, 308)), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.7 * pow(10, 308)),
                           atan(-1.7 * pow(10, 308)), S21_EPS);
}
END_TEST

//--------------------------s21_asin---------------------------------
START_TEST(test_s21_asin) {
  // testing values for s21_asin [-1 ; 1] with step 0.1
  for (double i = -1; i <= 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), S21_EPS);
  }
  ck_assert_ldouble_eq(s21_asin(1), asin(1));
  // testing NAN for s21_asin
  ck_assert_ldouble_nan(s21_asin(S21_PI));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF_POS));
  ck_assert_ldouble_nan(s21_asin(S21_INF_NEG));
}
END_TEST

//--------------------------s21_acos---------------------------------
START_TEST(test_s21_acos) {
  // testing values for s21_asin [-1 ; 1] with step 0.1
  for (double i = -1; i <= 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), S21_EPS);
  }
  ck_assert_ldouble_eq(s21_acos(1), acos(1));

  // testing NAN for s21_acos
  ck_assert_ldouble_nan(s21_acos(S21_PI));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_INF_POS));
  ck_assert_ldouble_nan(s21_acos(S21_INF_NEG));
}
END_TEST

//--------------------------s21_abs---------------------------------
START_TEST(test_s21_abs) {
  for (int i = -5; i <= 100; i += 1) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
  ck_assert_int_eq(s21_abs('a'), abs('a'));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

//--------------------------s21_sin---------------------------------
START_TEST(s21_sin_test) {
  // testing values for s21_sin [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), S21_EPS);
  }

  // testing NAN for s21_sin
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF_POS));
  ck_assert_ldouble_nan(s21_sin(S21_INF_NEG));
}
END_TEST

//--------------------------s21_cos---------------------------------
START_TEST(s21_cos_test) {
  // testing values for s21_acos [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), S21_EPS);
  }

  //  testing PI values for cos
  for (int i = -30; i <= 30; i++) {
    ck_assert_ldouble_eq_tol(s21_cos(i * S21_PI / 2), cos(i * S21_PI / 2),
                             S21_EPS);
  }

  // testing NAN for s21_sin
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF_POS));
  ck_assert_ldouble_nan(s21_cos(S21_INF_NEG));
}
END_TEST

//-------------------------s21_tan---------------------------------
START_TEST(s21_tan_test) {
  // testing values for s21_tan [-20 ; 20] with step 0.5
  for (double i = -20; i <= 20; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), S21_EPS);
  }

  // testing NAN for s21_tan
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF_POS));
  ck_assert_ldouble_nan(s21_tan(S21_INF_NEG));
}
END_TEST
//--------------------------s21_pow---------------------------------

START_TEST(test_s21_pow) {
  for (double i = 0.1; i <= 2.; i += 0.1) {
    for (double j = 0.1; j <= 2.; j += 0.1) {
      ck_assert_ldouble_eq_tol(s21_pow(i, j), pow(i, j), S21_EPS);
    }
  }
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-10, 3), pow(-10, 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-10, 2), pow(-10, 2), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(-1, -2.123));
  ck_assert_ldouble_nan(s21_pow(-1, 2.123));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_pow(10, 1), pow(10, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(10, -1), pow(10, -1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(10, 0), pow(10, 0), S21_EPS);
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, S21_INF_NEG),
                       pow(S21_INF_NEG, S21_INF_NEG));
  ck_assert_ldouble_eq(s21_pow(S21_INF_NEG, S21_INF_POS),
                       pow(S21_INF_NEG, S21_INF_POS));
  ck_assert_ldouble_eq(s21_pow(S21_INF_POS, S21_INF_POS),
                       pow(S21_INF_POS, S21_INF_POS));
}
END_TEST

//--------------------------s21_floor---------------------------------
START_TEST(test_s21_floor) {
  for (double i = -50.; i <= 50.; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), S21_EPS);
  }
  ck_assert_ldouble_eq_tol(s21_floor(BIGV), floor(BIGV), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-BIGV), floor(-BIGV), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-0.9999999999999999),
                           floor(-0.9999999999999999), S21_EPS);
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq(s21_floor(S21_INF_POS), floor(S21_INF_POS));
  ck_assert_ldouble_eq(s21_floor(S21_INF_NEG), floor(S21_INF_NEG));
}
END_TEST

//--------------------------s21_sqrt---------------------------------
START_TEST(test_s21_sqrt) {
  for (double i = 0.; i <= 50.; i += 0.5) {
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), S21_EPS);
  }
  ck_assert_ldouble_nan(s21_sqrt(S21_INF_NEG));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF_POS));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-10));
}
END_TEST

Suite *math_suite_create(void) {
  Suite *suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_s21_ceil);
  tcase_add_test(tcase_core, test_s21_fabs);
  tcase_add_test(tcase_core, test_s21_fmod);
  tcase_add_test(tcase_core, test_s21_exp);
  tcase_add_test(tcase_core, test_s21_log);
  tcase_add_test(tcase_core, test_s21_atan);
  tcase_add_test(tcase_core, test_s21_asin);
  tcase_add_test(tcase_core, test_s21_acos);
  tcase_add_test(tcase_core, test_s21_abs);
  tcase_add_test(tcase_core, s21_sin_test);
  tcase_add_test(tcase_core, s21_cos_test);
  tcase_add_test(tcase_core, s21_tan_test);
  tcase_add_test(tcase_core, test_s21_pow);
  tcase_add_test(tcase_core, test_s21_floor);
  tcase_add_test(tcase_core, test_s21_sqrt);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  int number_failed;
  Suite *suite = math_suite_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  // получаем количество проваленных тестов
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

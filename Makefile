CFLAGS = -Wall -Werror -Wextra -std=c11 -g
SOURCES = s21_abs.c s21_fabs.c s21_asin.c s21_acos.c s21_atan.c s21_ceil.c s21_sin.c s21_cos.c s21_tan.c s21_exp.c s21_pow.c s21_log.c s21_sqrt.c s21_fmod.c s21_floor.c 
OBJECTS = $(SOURCES:.c=.o)
TESTS = s21_math_tests.o
S21MATHLIB = s21_math.a

# пишет название текущей ОС
UNAME = $(shell uname -s)
FLAGS = -lcheck
#если ОС - Linux
ifeq ($(UNAME), Linux)
	FLAGS +=  -lm -lsubunit
  	OPEN=xdg-open
#если ОС - Darvin
else
	FLAGS += -fprofile-arcs -ftest-coverage
 	OPEN=open
endif

all: test


test: $(TESTS) $(S21MATHLIB)

	gcc  $^ -o test $(CFLAGS) $(FLAGS)
	rm -rf *.o 
	./test

$(TESTS): $(TESTS:.o=.c)
	gcc $(CFLAGS) -c $^  -o $@
	
	
$(S21MATHLIB): $(OBJECTS)
	gcc $(CFLAGS) -c $(SOURCES)

	ar rc $@ $^

	ranlib $@

style:
	clang-format -n -style=Google *.c *.h
	clang-format -i -style=Google *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h	

rebuild: clean all

gcov_report: clean $(TESTS)

	gcc -o test $(FLAGS) --coverage $(TESTS) $(SOURCES)
	./test

	lcov -t "a.out" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
	rm -rf test *.o *.a *gcda *gcno *info

clean:
	rm -rf test *.o *.a *.gch *.gcda report *.gcno *.info

.PHONY: all, test, style, rebuild, gcov_report, clean

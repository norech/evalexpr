CC = gcc
CFLAGS = -W -Wall -Werror -I./include -L./lib -g3
LFLAGS = -lmy
TEST_FLAGS = $(LFLAGS) -lcriterion --coverage
TARGET = eval_expr
TARGET_TEST = unit_test

SRC = 	eval_expr.c \
		expr.c \
		operators.c \
		parser_brackets.c \
		parser.c \
		tokens.c

TESTS =	tests/test_eval_expr.c \
		tests/test_expr.c \
		tests/test_operators.c \
		tests/test_tokens.c

all: build_lib build_all

build_lib:
	make -C ./lib/my/

build_all: ${TARGET}

tests_run: clean_tests build_lib
	${CC} ${CFLAGS} ${TEST_FLAGS} -o ${TARGET_TEST} ${SRC} ${TESTS} ${LFLAGS}
	./${TARGET_TEST} --verbose

clean_tests:
	rm -rf ${TARGET_TEST}

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} main.c ${LFLAGS}

clean:
	rm -f ${TARGET}

fclean: clean
	rm -f ${LIB} *.gc* unit_test

re: fclean all

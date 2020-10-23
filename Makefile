CC = gcc
CFLAGS = -W -Wall -Werror -I./include -L./lib -g3
LFLAGS = -lmy
TEST_FLAGS = $(LFLAGS) -lcriterion --coverage
TARGET = eval_expr

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

all: build_lib build_all clean

build_lib:
	make -C ./lib/my/

build_all: ${TARGET}

tests_run:
	${CC} ${CFLAGS} ${TEST_FLAGS} -o unit_test ${SRC} ${TESTS} ${LFLAGS}
	./unit_test --verbose

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} main.c ${LFLAGS}

clean:
	rm -f ${TARGET}

fclean: clean
	rm -f ${LIB} *.gc* unit_test

re: fclean all

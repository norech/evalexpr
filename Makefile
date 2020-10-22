CC = gcc
CFLAGS = -W -Wall -Werror -I./include -L./lib -g3
CFLAGS_TEST = ${CFLAGS} -Wno-stringop-truncation --coverage
LIBS = -lmy
LIBS_TEST = $(LIBS) -lcriterion
SRC = ${wildcard ./*.c}
TEST_SRC = $(filter-out ./main.c, $(SRC))
TEST_FILES = ./tests/*.c
TARGET = evalexpr

all: build_lib build_all clean

build_lib:
	make -C ./lib/my/

build_all: ${TARGET}

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${LIBS}

test:
	${CC} ${CFLAGS_TEST} -o unit_test ${TEST_SRC} ${TEST_FILES} ${LIBS_TEST}

coverage: test
	gcovr

clean:
	rm ${OBJ} *.gc* unit_test 2>/dev/null || exit 0

fclean: clean
	rm ${LIB} 2>/dev/null || exit 0

re: fclean all

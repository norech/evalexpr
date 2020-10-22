CC = gcc
CFLAGS = -W -Wall -Werror -I./include -L./lib -g3
CFLAGS_TEST = ${CFLAGS} -Wno-stringop-truncation -lcriterion --coverage
LIBS = -lmy
SRC = ${wildcard ./*.c}
TEST_FILES = ./tests/*.c
TARGET = evalexpr

all: build_lib build_all clean

build_lib:
	make -C ./lib/my/

build_all: ${TARGET}

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${LIBS}

coverage: test
	gcovr

clean:
	rm ${OBJ} *.gc* unit_test 2>/dev/null || exit 0

fclean: clean
	rm ${LIB} 2>/dev/null || exit 0

re: fclean all

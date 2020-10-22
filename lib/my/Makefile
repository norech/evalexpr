##
## EPITECH PROJECT, 2020
## libmy
## File description:
## My library
##

CC = gcc

AR = ar rc

CFLAGS = -W -Wall -Werror -I./include

CFLAGS_TEST = ${CFLAGS} -Wno-stringop-truncation -lcriterion --coverage

SRC = ${wildcard ./src/*.c}

OBJ = ${SRC:.c=.o}

TARGET = libmy.a

TEST_FILES = ../../tests/lib/my/*.c

all: build_all clean

build_all: ${OBJ}
	${AR} ${TARGET} ${OBJ}
	cp ${TARGET} ../
	mkdir -p ../../include
	cp ./include/*.h ../../include

coverage: test
	gcovr

clean:
	rm -f ${OBJ} *.gc* unit_test

fclean: clean
	rm -f ${TARGET}

re: fclean all

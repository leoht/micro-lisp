CC = gcc
FLAGS = -Wall
SOURCES = lisp.c

all:
	${CC} ${FLAGS} ${SOURCES} -o lisp
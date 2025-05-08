CPPCOMP=g++
NAME=counting-circle
INCLUDE=include
CPPFLAGS=-I ${INCLUDE} -march=native -O2 -o ${NAME}.out
SOURCE=src/*

all: clean build

clean:
	rm -f ${NAME}.out
build:
	${CPPCOMP} ${SOURCE} ${CPPFLAGS}

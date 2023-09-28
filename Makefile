CC = g++
INCLUDE_DIR = ./include/
SOURCE_DIR = ./source/
FLAGS = -g -O2 -Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Wold-style-cast -Wuninitialized  -Winit-self  -Wshadow  -Wparentheses -Wdangling-else 
STD_VERSION = --std=c++20
LINKER_FLAGS = 

OBJS = main.o
OUT = cbake

all: ${OBJS}
	${CC} -g ${OBJS} -o ${OUT} ${LINKER_FLAGS}
	make clean

main.o:
	${CC} -c ${FLAGS} ${SOURCE_DIR}main.cpp ${STD_VERSION}

clean:
	rm -f ${OBJS}

CC = gcc
INCLUDE_DIR = ./include/
SOURCE_DIR = ./source/
FLAGS = -g -O2 -Wall -Wextra -Wpedantic -Werror -Wnon-virtual-dtor -Wold-style-cast -Wunused-parameter -Wuninitialized  -Winit-self  -Wshadow  -Wparentheses -Wdangling-else 
STD_VERSION = --std=c17
LINKER_FLAGS = 

OBJS = main.o logger.o
OUT = cbake

all: ${OBJS}
	${CC} -g ${OBJS} -o ${OUT} ${LINKER_FLAGS}
	make clean

main.o:
	${CC} -c ${FLAGS} ${SOURCE_DIR}main.c ${STD_VERSION}

logger.o logger.h:
	${CC} -c ${FLAGS} ${SOURCE_DIR}/utils/logger.c ${STD_VERSION}

clean:
	rm -f ${OBJS}

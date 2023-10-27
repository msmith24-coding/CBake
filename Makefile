CC = g++
CXXFLAGS = -g -O2 --std=c++17 -Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Wold-style-cast -Wuninitialized -Winit-self -Wparentheses -Wdangling-else 

INCLUDE_DIR = ./include
SOURCE_DIR = ./source
OBJS = main.o Logger.o

ifeq ($(OS),Windows_NT)
RM_CMD = del /Q /F
OUT = cbake.exe
else
RM_CMD = rm -rf
OUT = cbake
endif

all: ${OBJS}
	${CC} ${CXXFLAGS} ${OBJS} -o ${OUT} -I${INCLUDE_DIR}

main.o:
	${CC} -c ${CXXFLAGS} ${SOURCE_DIR}/main.cpp -I${INCLUDE_DIR}

Logger.o:
	${CC} -c ${CXXFLAGS} ${SOURCE_DIR}/utils/Logger.cpp -I${INCLUDE_DIR}

.PHONY: clean
clean:
	${RM_CMD} ${OBJS} ${OUT}

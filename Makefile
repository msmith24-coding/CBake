CC = g++
CXXFLAGS = -std=c++17

FILES = src/*.cpp
INCLUDE = -I./include
OUT = cbake

build:
	${CC} ${CXXFLAGS} ${FILES} ${INCLUDE} -o ${OUT}
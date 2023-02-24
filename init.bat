g++ --std=c++20 -c ./src/*.cpp
md bin
g++ *.o -o ./bin/cbake
del *.o
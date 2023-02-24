g++ --std=c++20 -c ./src/*.cpp
mkdir ./bin
g++ *.o -o ./bin/cbake
rm -rf *.o
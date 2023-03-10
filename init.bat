g++ -Wall --std=c++20 -c ./src/main.cpp ./src/utils/*.cpp ./src/lexer/*.cpp ./src/parser/*.cpp -I./includes
g++ *.o -o ./bin/cbake
del *.o
g++ -O2 -Wall -Wextra -Wpedantic -Werror --std=c++20 -Wnon-virtual-dtor -Wold-style-cast -Wunused-parameter -Wuninitialized  -Winit-self  -Wshadow  -Wparentheses -Wdangling-else -c ./src/main.cpp ./src/lexer/*.cpp ./src/parser/*.cpp ./src/utils/*.cpp
md bin
g++ *.o -o ./bin/cbake
del *.o
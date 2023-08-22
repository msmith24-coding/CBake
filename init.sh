g++ -Wall --std=c++20 -c ./src/main.cpp -I./includes
g++ *.o -o ./bin/cbake
rm -rf *.o
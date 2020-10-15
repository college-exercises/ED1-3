#! /bin/sh

g++ -o -wall ./src/main.cpp -std=c++11 -pthread -o ./main

./main

rm ./main

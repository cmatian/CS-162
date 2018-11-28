CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o menu.o game.o dice.o
	$(CXX) main.o menu.o game.o dice.o -o main

main.o: main.cpp
	$(CXX) -c main.cpp

ant.o: menu.cpp menu.hpp
	$(CXX) -c menu.cpp

board.o: game.cpp game.hpp
	$(CXX) -c game.cpp

validation.o: dice.cpp dice.hpp
	$(CXX) -c dice.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

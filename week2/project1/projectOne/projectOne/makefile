CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o ant.o board.o validation.o
	$(CXX) main.o ant.o board.o validation.o -o main

main.o: main.cpp
	$(CXX) -c main.cpp

ant.o: ant.cpp ant.hpp
	$(CXX) -c ant.cpp

board.o: board.cpp board.hpp
	$(CXX) -c board.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) -c validation.cpp

clean:
	rm *.o main

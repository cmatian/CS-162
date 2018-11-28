CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o count.o
	$(CXX) main.o count.o -o run

main.o: main.cpp
	$(CXX) -c main.cpp

message.o: count.cpp count.hpp
	$(CXX) -c count.cpp

clean:
	rm *.o run

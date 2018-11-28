CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o nodes.o menu.o validation.o
	$(CXX) $(CXXFLAGS) main.o nodes.o menu.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CXXFLAGS) -c menu.cpp

nodes.o: nodes.cpp nodes.hpp
	$(CXX) $(CXXFLAGS) -c nodes.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

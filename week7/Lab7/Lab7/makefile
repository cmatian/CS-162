CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o queue.o menu.o validation.o
	$(CXX) $(CXXFLAGS) main.o queue.o menu.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CXXFLAGS) -c menu.cpp

queue.o: queue.cpp queue.hpp
	$(CXX) $(CXXFLAGS) -c queue.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

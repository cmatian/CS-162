CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o sorting.o validation.o
	$(CXX) $(CXXFLAGS) main.o sorting.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

sorting.o: sorting.cpp sorting.hpp
	$(CXX) $(CXXFLAGS) -c sorting.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

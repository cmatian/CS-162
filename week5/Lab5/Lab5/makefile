CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o recursions.o validation.o
	$(CXX) $(CXXFLAGS) main.o recursions.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

recursions.o: recursions.cpp recursions.hpp
	$(CXX) $(CXXFLAGS) -c recursions.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

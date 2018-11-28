CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o zoo.o validation.o animal.o simulation.o
	$(CXX) $(CXXFLAGS) main.o zoo.o validation.o animal.o simulation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

zoo.o: zoo.cpp zoo.hpp
	$(CXX) $(CXXFLAGS) -c zoo.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

animal.o: animal.cpp animal.hpp
	$(CXX) $(CXXFLAGS) -c animal.cpp

simulation.o: simulation.cpp simulation.hpp
	$(CXX) $(CXXFLAGS) -c simulation.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

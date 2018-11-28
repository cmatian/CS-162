CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o university.o building.o person.o validation.o
	$(CXX) $(CXXFLAGS) main.o university.o building.o person.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

university.o: university.cpp university.hpp
	$(CXX) $(CXXFLAGS) -c university.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

building.o: building.cpp building.hpp
	$(CXX) $(CXXFLAGS) -c building.cpp

person.o: person.cpp person.hpp
	$(CXX) $(CXXFLAGS) -c person.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

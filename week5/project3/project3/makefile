CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o character.o menu.o combat.o validation.o
	$(CXX) $(CXXFLAGS) main.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o character.o menu.o validation.o combat.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

character.o: character.cpp character.hpp
	$(CXX) $(CXXFLAGS) -c character.cpp

vampire.o: vampire.cpp vampire.hpp
	$(CXX) $(CXXFLAGS) -c vampire.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	$(CXX) $(CXXFLAGS) -c barbarian.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	$(CXX) $(CXXFLAGS) -c bluemen.cpp

medusa.o: medusa.cpp medusa.hpp
	$(CXX) $(CXXFLAGS) -c medusa.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	$(CXX) $(CXXFLAGS) -c harrypotter.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CXXFLAGS) -c menu.cpp

combat.o: combat.cpp combat.hpp
	$(CXX) $(CXXFLAGS) -c combat.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

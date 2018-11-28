CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o game.o player.o spaces.o lobby.o courtyard.o easthall.o eaststudy.o westhall.o weststudy.o validation.o
	$(CXX) $(CXXFLAGS) main.o game.o player.o spaces.o lobby.o courtyard.o easthall.o eaststudy.o westhall.o weststudy.o validation.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.cpp game.hpp
	$(CXX) $(CXXFLAGS) -c game.cpp

player.o: player.cpp player.hpp
	$(CXX) $(CXXFLAGS) -c player.cpp

spaces.o: spaces.cpp spaces.hpp
	$(CXX) $(CXXFLAGS) -c spaces.cpp

lobby.o: lobby.cpp lobby.hpp
	$(CXX) $(CXXFLAGS) -c lobby.cpp

courtyard.o: courtyard.cpp courtyard.hpp
	$(CXX) $(CXXFLAGS) -c courtyard.cpp

easthall.o: easthall.cpp easthall.hpp
	$(CXX) $(CXXFLAGS) -c easthall.cpp

eaststudy.o: eaststudy.cpp eaststudy.hpp
	$(CXX) $(CXXFLAGS) -c eaststudy.cpp

westhall.o: westhall.cpp westhall.hpp
	$(CXX) $(CXXFLAGS) -c westhall.cpp

weststudy.o: weststudy.cpp weststudy.hpp
	$(CXX) $(CXXFLAGS) -c weststudy.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CXXFLAGS) -c validation.cpp

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck main

clean:
	rm *.o main

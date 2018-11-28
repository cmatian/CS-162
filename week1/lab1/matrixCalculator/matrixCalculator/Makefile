CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

output: main.o matrix.o determinant.o
	$(CXX) main.o matrix.o determinant.o -o output

main.o: main.cpp
	$(CXX) -c main.cpp

message.o: matrix.cpp matrix.hpp
	$(CXX) -c matrix.cpp

determinant.o: determinant.cpp determinant.hpp
	$(CXX) -c determinant.cpp

clean:
	rm *.o output

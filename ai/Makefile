## Author: Alexander Corley, Jacob Hanson, Ryan Lynn
## 10-28-2017

CXX=g++
CXXFLAGS=-std=c++11 -Wall -g
SOURCE=$(wildcard *.cpp)
OBJECTS=$(SOURCE:.cpp=.o)
EXE=solve

EXE: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE)

clean:
	rm -f $(OBJECTS) $(EXE)


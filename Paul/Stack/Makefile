CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = main.cpp stack.cpp

all: BST

BST: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o Target
	rm -f *.o

clean:
	rm -f Target
CC=g++
HEADERS = all.hpp node.h Tree.h
OBJ = main.o Tree.o
TARGET = p0
CXXFLAGS=-g -std=c++11

%.o: %.cpp $(HEADERS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)


clean: 
	rm $(OBJ) $(TARGET) 

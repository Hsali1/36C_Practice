# Makefile for Program

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp hash.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = hash.h

# Target
TARGET = Program

# Rule to build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	rm -f $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

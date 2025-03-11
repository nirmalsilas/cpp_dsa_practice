# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -O2

# Target executable
TARGET = app

# Source file
SRC = main.cpp

# Default target
all: $(TARGET)

# Rule to compile main.cpp
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: $(TARGET)
	./$(TARGET)
	
# Clean rule
clean:
	rm -f $(TARGET)

.PHONY: all clean
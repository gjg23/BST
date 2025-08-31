# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Files
SRCS = $(SRC_DIR)/bst_demo.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = $(BIN_DIR)/bst_demo

# Default target
all: $(EXEC)

# Compile executable
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile object files
%.o: %.cpp $(INCLUDE_DIR)/bst.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run the demo
run: $(EXEC)
	./$(EXEC)

# Clean object files and executable
clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)

.PHONY: all run clean

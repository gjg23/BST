# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
SRCS = $(SRC_DIR)/bst_demo.cpp $(SRC_DIR)/bst_cli.cpp
OBJS = $(BIN_DIR)/bst_demo.o $(BIN_DIR)/bst_cli.o

# Executables
EXEC_DEMO = $(BIN_DIR)/bst_demo
EXEC_CLI  = $(BIN_DIR)/bst_cli
EXECS = $(EXEC_DEMO) $(EXEC_CLI)

# Default target: build all executables
all: $(EXECS)

# Compile bst_demo
$(EXEC_DEMO): $(BIN_DIR)/bst_demo.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Compile bst_cli
$(EXEC_CLI): $(BIN_DIR)/bst_cli.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule for object files in bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run the demos
run_demo: $(EXEC_DEMO)
	./$(EXEC_DEMO)

run_cli: $(EXEC_CLI)
	./$(EXEC_CLI)

# Clean object files and executables
clean:
	rm -f $(BIN_DIR)/*.o $(EXECS)

.PHONY: all run_demo run_cli clean

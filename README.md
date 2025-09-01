# Binary Search Tree (BST) Demo

**Course:** Data Structures and Algorithms  
**Type:** Class assignment 

---

## Overview

This project implements a **Binary Search Tree (BST)** in C++ as part of a **Data Structures and Algorithms** class assignment.  

The BST is implemented as a **templated class**, supporting the following operations:  

- Insert elements  
- Search for elements (`contains`)  
- Find minimum and maximum values  
- Print elements in-order (sorted order)  

This project also includes **interactive command-line demos** to test and demonstrate the BST’s functionality.

---

## Project Structure

```
project/
├── src/
│   ├── bst_demo.cpp    # demo for example input.txt
│   └── bst_cli.cpp     # Interactive demo for BST
├── include/
│   ├── bst.hpp         # BST class declarations
│   └── bst.tpp         # BST template implementations
├── bin/                # Compiled executables and object files
├── examples/
│   ├── input.txt
│   └── output.txt
├── Makefile
└── README.md
```

---

## Features

- **Templated BST** — works with any comparable data type (currently tested with `int`)  
- **Interactive CLI** — allows inserting values, checking for existence, printing the tree, and finding min/max  
- **Example scripts** — included in `examples/` to demonstrate the BST with pre-made input and output  

---

## How to Build

Make sure you have `g++` installed (supports C++17). Then run:

```bash
make
```

This will build both executables:  

- `bin/bst_demo` → main interactive demo  
- `bin/bst_cli` → alternative CLI demo  

---

## How to Run

### Run interactive demo:
```bash
make run_demo
```

### Run CLI demo:
```bash
make run_cli
```

### Run CLI demo with example input:
```bash
./bin/bst_demo < examples/input.txt > examples/output.txt
```

This will feed pre-defined input to the BST and generate a corresponding output file.

---

## Clean Build

To remove compiled object files and executables:

```bash
make clean
```

---

## Notes

- This project was completed as a **class assignment** for FSU’s program in Computer Science.  
- The implementation demonstrates **low-level C++ skills**, including templates, recursion, dynamic memory management, and console I/O.  
- The `examples/` folder contains sample input/output to showcase the BST’s functionality for portfolio purposes.  

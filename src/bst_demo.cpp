// bst_demo.cpp
// Demo for binary search tree

#include "bst.hpp"

#include <iostream>
#include <limits>

int main() {
	// init tree
	binary_search_tree<int> tree;
	int choice, value;

	std::cout << "=== Binary Search Tree Demo ===\n";
	std::cout << "\nChoose an option:\n";
	std::cout << "1. Insert value\n";
	std::cout << "2. Print tree (in-order)\n";
	std::cout << "3. Check if value exists\n";
	std::cout << "4. Get min\n";
	std::cout << "5. Get max\n";
	std::cout << "6. Exit\n";

	// input loop
	while (true) {
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: // Insert
			std::cout << "Enter value to insert: ";
			std::cin >> value;
			tree.insert(value);
			std::cout << value << " inserted.\n";
			break;

		case 2: // Print
			std::cout << "Tree contents (in-order):\n";
			tree.print();
			break;

		case 3: // Contains
			std::cout << "Enter value to search: ";
			std::cin >> value;
			if (tree.contains(value))
				std::cout << value << " exists in the tree.\n";
			else
				std::cout << value << " not found.\n";
			break;

		case 4: // Min
			if (!tree.is_empty())
				std::cout << "Min value: " << tree.min() << std::endl;
			else
				std::cout << "Tree is empty.\n";
			break;

		case 5: // Max
			if (!tree.is_empty())
				std::cout << "Max value: " << tree.max() << std::endl;
			else
				std::cout << "Tree is empty.\n";
			break;

		case 6: // Exit
			std::cout << "Exiting program.\n";
			return 0;

		default:
			std::cout << "Invalid choice. Try again." << std::endl;
		}
	}
}
// bst.hpp
// Header for BST

#ifndef BST_HPP
#define BST_HPP

#include <utility>
#include <iostream>

template<typename Comparable>
class binary_search_tree
{
private:
	// binary node structure
	struct binary_node {
		Comparable element;
		binary_node *left;
		binary_node *right;

		// construct left and right nodes
		binary_node(const Comparable & an_element, binary_node *l, binary_node *r) :
		element { an_element }, left{ l }, right{ r } { }

		binary_node(const Comparable && an_element, binary_node *l, binary_node *r) :
		element { std::move(an_element) }, left{ l }, right{ r } { }
	};

	// the root node
	binary_node *root = nullptr;

	// insert node
	void insert (const Comparable & x, binary_node * & t);
	
	// get min or max node
	binary_node * min(binary_node *t);
	binary_node * max(binary_node *t);

	// check if empty
	bool is_empty(binary_node *t);

	// check if there is child
	bool contains(const Comparable & x, binary_node *t);

	// print contents
	void print(binary_node *t, std::ostream & out);

public:
	// the binary tree (first node is initialized to null)
	binary_search_tree();

	// Get min or max element
	const Comparable & min();
	const Comparable & max();
	
	// check if node is parent of another
	bool contains(const Comparable & x);
	
	// check if end of tree
	bool is_empty();

	// add node as child to another node
	void insert(const Comparable & x);

	// print node contents
	void print(ostream & out = std::cout);
};

// implementation file
#include "bst.tpp"

#endif
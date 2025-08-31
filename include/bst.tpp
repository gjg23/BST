// bst.tpp
// Implementation for BST template class

// Constructor
template<typename Comparable>
binary_search_tree<Comparable>::binary_search_tree() {
	root = nullptr;
}

// insert node
template<typename Comparable>
void binary_search_tree<Comparable>::insert(const Comparable & x, binary_node * & t) {
if (t == nullptr) {
	t = new binary_node(x, nullptr, nullptr);
}
else if (x < t->element) {
	insert(x, t->left);
}
else if(x > t->element) {
	insert(x, t->right);
}
}

// get min node
template<typename Comparable>
typename binary_search_tree<Comparable>::binary_node *
binary_search_tree<Comparable>::min(binary_node *t) {
if (t == nullptr) { //empty tree
	return nullptr;
}
else if (t->left == nullptr) { //no left pointer
	return t;
}
else {
	return min(t->left); //move to next left child
}
}

// get max node
template<typename Comparable>
typename binary_search_tree<Comparable>::binary_node *
binary_search_tree<Comparable>::max(binary_node *t) {
if (t->right != nullptr) {
	return max(t->right);
}
return t;
}

// check if tree is empty (private)
template<typename Comparable>
bool binary_search_tree<Comparable>::is_empty(binary_node *t) {
if (t == nullptr) {
	return true;
} else {
	return false;
}
}

// check if node exists (private)
template<typename Comparable>
bool binary_search_tree<Comparable>::contains(const Comparable & x, binary_node *t) {
if (t == nullptr) {
	return false;
}
else if (x < t->element) {
	return contains(x, t->left);
}
else if(x > t->element) {
	return contains(x, t->right);
}
else {
	return true;
}
}

// print contents of tree (private)
template<typename Comparable>
void binary_search_tree<Comparable>::print(binary_node *t, std::ostream & out ) {
if (t != nullptr) {
	print(t->left, out);
	out << t->element << std::endl;
	print (t->right, out);
}
}

// PUBLIC METHODS

// get min element
template<typename Comparable>
const Comparable & binary_search_tree<Comparable>::min() {
return min(root)->element;
}

// get max element
template<typename Comparable>
const Comparable & binary_search_tree<Comparable>::max() {
return max(root)->element;
}

// check if node exists (public)
template<typename Comparable>
bool binary_search_tree<Comparable>::contains(const Comparable & x) {
return contains(x, root);
}

// check if tree is empty (public)
template<typename Comparable>
bool binary_search_tree<Comparable>::is_empty() {
return is_empty(root);
}

// insert new element (public)
template<typename Comparable>
void binary_search_tree<Comparable>::insert(const Comparable & x) {
insert(x, root);
}

// print tree (public)
template<typename Comparable>
void binary_search_tree<Comparable>::print(std::ostream & out) {
print(root, out);
}

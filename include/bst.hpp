// Header for BST

#include <utility>
#include <iostream>

template<typename Comparable>
class binary_search_tree
{
    public:
    binary_search_tree()
    {
        root = nullptr;
    }

    const Comparable & min( )
    {
        return min(root)->element;
    }

    const Comparable & max( )
    {
        return max(root)->element;
    }
    
    bool contains( const Comparable & x )
    {
        return contains(x, root);
    }
    
    bool is_empty( ) 
    {
        return is_empty(root);
    }

    void insert( const Comparable & x )
    {
        insert(x, root);
    }

    void print( ostream & out = cout)
    {
        print(root, out);
    }

    
    private:
    
    struct binary_node
    {
        Comparable element;
        binary_node *left;
        binary_node *right;

        binary_node(const Comparable & an_element, binary_node *l, binary_node *r) :
        element { an_element }, left{ l }, right{ r } { }
        
        binary_node(const Comparable && an_element, binary_node *l, binary_node *r) :
        element { std::move(an_element) }, left{ l }, right{ r } { }
    };

    binary_node *root = nullptr;

    void insert ( const Comparable & x, binary_node * & t )
    {
        if (t == nullptr)
        {
            t = new binary_node(x, nullptr, nullptr);
        }
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if(x > t->element)
        {
            insert(x, t->right);
        }
    }
    
    binary_node * min(binary_node *t)
    {
        if (t == nullptr) //empty tree
        {
            return nullptr;
        }
        else if (t->left == nullptr) //no left pointer
        {
            return t;
        }
        else
        {
            return min(t->left); //move to next left child
        }
    }

    binary_node * max(binary_node *t)
    {
        if (t->right != nullptr)
        {
            return max(t->right);
        }
        return t;
    }

    bool is_empty(binary_node *t)
    {
        if (t == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool contains(const Comparable & x, binary_node *t)
    {
        if (t == nullptr)
        {
            return false;
        }
        else if (t < t->element)
        {
            return contains(x, t->left);
        }
        else if(t > t->element)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;
        }
    }

    void print(binary_node *t, ostream & out )
    {
        if (t != nullptr)
        {
            print(t->left, out);
            out << t->element << endl;
            print (t->right, out);
        }
    }
};
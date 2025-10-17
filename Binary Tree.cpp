#include <iostream>

using namespace std;

// Define a structure for a tree node
struct Node
{
    int data;    // Value stored in the node
    Node *left;  // Pointer to the left child
    Node *right; // Pointer to the right child
};

// Function to create a new node with a given value
Node *newnode(int data)
{
    Node *node = new Node;           // Allocate memory for a new node
    node->data = data;               // Assign the value
    node->left = node->right = NULL; // No childs yet
    return node;                     // Return the created node
}

int main()
{

    // Build the binary tree
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    return 0;
}

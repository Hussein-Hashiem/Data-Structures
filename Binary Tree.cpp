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
    Node *node = new Node;              // Allocate memory for a new node
    node->data = data;                  // Assign the value
    node->left = node->right = nullptr; // No children yet
    return node;                        // Return the created node
}

// Preorder Traversal (Root → Left → Right)
void PreorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';      // Visit root
        PreorderTraversal(root->left);  // Traverse left subtree
        PreorderTraversal(root->right); // Traverse right subtree
    }
}

// Inorder Traversal (Left → Root → Right)
void InorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        InorderTraversal(root->left);  // Traverse left subtree
        cout << root->data << ' ';     // Visit root
        InorderTraversal(root->right); // Traverse right subtree
    }
}

// Postorder Traversal (Left → Right → Root)
void PostorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        PostorderTraversal(root->left);  // Traverse left subtree
        PostorderTraversal(root->right); // Traverse right subtree
        cout << root->data << ' ';       // Visit root
    }
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

    cout << "Preorder: ";
    PreorderTraversal(root);
    cout << '\n';

    cout << "Inorder: ";
    InorderTraversal(root);
    cout << '\n';

    cout << "Postorder: ";
    PostorderTraversal(root);
    cout << '\n';

    return 0;
}

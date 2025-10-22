#include <iostream>
#include <queue>

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

// Depth First Traversal (DFS)

// Preorder Traversal (Root → Left → Right)
void PreorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << ' ';      // Visit root
    PreorderTraversal(root->left);  // Traverse left subtree
    PreorderTraversal(root->right); // Traverse right subtree
}

// Inorder Traversal (Left → Root → Right)
void InorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    InorderTraversal(root->left);  // Traverse left subtree
    cout << root->data << ' ';     // Visit root
    InorderTraversal(root->right); // Traverse right subtree
}

// Postorder Traversal (Left → Right → Root)
void PostorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    PostorderTraversal(root->left);  // Traverse left subtree
    PostorderTraversal(root->right); // Traverse right subtree
    cout << root->data << ' ';       // Visit root
}

// Breadth First Traversal (BFS)
void LevelorderTraversal(Node *root)
{
    if (root == nullptr)
        return;      // Return if tree is empty
    queue<Node *> Q; // Create a queue to store nodes
    Q.push(root);    // Start with the root node
    while (!Q.empty())
    {
        int LevelSize = Q.size(); // Number of nodes in the current level
        for (int i = 0; i < LevelSize; i++)
        {
            Node *curr = Q.front();    // Get the front node
            cout << curr->data << ' '; // Print current node's data
            if (curr->left != nullptr) // Enqueue left child if exists
                Q.push(curr->left);
            if (curr->right != nullptr) // Enqueue right child if exists
                Q.push(curr->right);
            Q.pop(); // Remove the processed node
        }
        cout << '\n';
    }
}

// Delete Binary Tree
void DeleteBinaryTree(Node *&current)
{
    if (current == nullptr)
        return;
    DeleteBinaryTree(current->left);
    DeleteBinaryTree(current->right);
    delete current;
    current = nullptr; // Avoid dangling pointer
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

    cout << "Levelorder: ";
    LevelorderTraversal(root);
    cout << '\n';

    return 0;
}

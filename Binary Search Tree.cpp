#include <iostream>
#include <queue>

using namespace std;

// Define a structure for a tree node
struct TreeNode
{
    int data;        // Value stored in the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child
};

// Function to create a new node with a given value
TreeNode *newnode(int data)
{
    TreeNode *node = new TreeNode;      // Allocate memory for a new node
    node->data = data;                  // Assign the value
    node->left = node->right = nullptr; // No children yet
    return node;                        // Return the created node
}

TreeNode *insert(TreeNode *root, int data)
{
    if (root == nullptr)
        return newnode(data); // base case: create node if tree is empty
    if (data < root->data)
        root->left = insert(root->left, data); // insert in left subtree if smaller
    else
        root->right = insert(root->right, data); // insert in right subtree if >=
    return root;
}

bool search(TreeNode *root, int value)
{
    if (root == nullptr)
        return false; // Empty tree or not found
    if (root->data == value)
        return true; // Value found
    if (value < root->data)
        return search(root->left, value); // Search in left subtree
    return search(root->right, value);    // Search in right subtree
}

TreeNode *findMin(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

TreeNode *findMax(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

TreeNode *removeNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr; // Base case: empty tree
    if (key < root->data)
        root->left = removeNode(root->left, key); // Search in left subtree
    else if (key > root->data)
        root->right = removeNode(root->right, key); // Search in right subtree
    else
    {
        // Node found
        if (root->left == nullptr) // Case 1: no left child
        {
            TreeNode *temp = root->right; // Replace with right child
            delete root;                  // Delete current node
            return temp;
        }
        else if (root->right == nullptr) // Case 2: no right child
        {
            TreeNode *temp = root->left; // Replace with left child
            delete root;                 // Delete current node
            return temp;
        }
        else // Case 3: two children
        {
            TreeNode *mn = findMin(root->right);             // Find inorder successor (min in right subtree)
            root->data = mn->data;                           // Copy successor's data
            root->right = removeNode(root->right, mn->data); // Delete successor node
        }
    }
    return root; // Return updated root
}

// Breadth First Traversal (BFS)
void LevelorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;          // Return if tree is empty
    queue<TreeNode *> Q; // Create a queue to store nodes
    Q.push(root);        // Start with the root node
    while (!Q.empty())
    {
        int LevelSize = Q.size(); // Number of nodes in the current level
        for (int i = 0; i < LevelSize; i++)
        {
            TreeNode *curr = Q.front(); // Get the front node
            cout << curr->data << ' ';  // Print current node's data
            if (curr->left != nullptr)  // Enqueue left child if exists
                Q.push(curr->left);
            if (curr->right != nullptr) // Enqueue right child if exists
                Q.push(curr->right);
            Q.pop(); // Remove the processed node
        }
        cout << '\n';
    }
}

int main()
{
    TreeNode *root = nullptr;

    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 30);
    root = insert(root, 90);
    root = insert(root, 15);

    LevelorderTraversal(root);
    return 0;
}

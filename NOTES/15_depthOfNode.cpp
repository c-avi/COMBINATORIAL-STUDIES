#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function ti find depth of a specific node (value) in the binary tree
int findNodeDepth (Node* root, int target, int depth = 0) {
    if (root == nullptr)
        return -1;
    if (root->data == target)
        return depth;

    // Search in the left subtree
    int left = findNodeDepth(root->left, target, depth + 1);
    if (left != -1)
        return left;
    
    // Search in the right subtree
    return findNodeDepth(root->right, target, depth + 1);
}

// Driver code
int main() {
    /*
        1
       /\
      2  3
     /\
    4  5*/

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int target = 5;
    int result = findNodeDepth(root, target);

    if (result != -1)
        cout << "Depth of node " << target << ": " << result << "\n";
    else 
        cout << "Node " << target << " not found in the tree." << "\n";

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

// Define the structure of a tree node
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to print the left view of the binary tree
void leftView(Node* root) {
    if (root == nullptr) 
        return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at current level

        for (int  i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            // Print the first node of each level
            if (i == 0)
                cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

// Example usage
int main() {
    /*
        1
       /\
      2  3
     /\   \
    4  5   6*/

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Left View of Binary Tree: ";
    leftView(root);
    return 0;
}
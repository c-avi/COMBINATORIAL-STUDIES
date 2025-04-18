#include <iostream>
#include <queue>
using namespace std;

// Define a structure of a tree node
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {} 
};

// Function to build tree with level wise from user input
Node* buildTree() {
    int data;
    cout << "Enter root node value (-1 for NULL) : ";
    cin >> data;
    if (data == -1) return nullptr;

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q. front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Driver code
int main() {
    Node* root = buildTree();
    cout << "\nHeight of the binary tree is: " << height(root); 
    return 0;
}

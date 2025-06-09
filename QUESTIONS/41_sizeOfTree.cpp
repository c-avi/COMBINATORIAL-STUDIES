#include <iostream>
#include <queue>
using namespace std;

// Definition for Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to compute size of binary tree
class Solution {
  public:
    int getSize(Node* node) {
        if (node == NULL)
            return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }
};

// Function to build tree using level order input
Node* buildTree() {
    cout << "Enter root node value (-1 for NULL): ";
    int rootVal;
    cin >> rootVal;

    if (rootVal == -1)
        return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

int main() {
    Node* root = buildTree();

    Solution sol;
    int size = sol.getSize(root);

    cout << "Size of the binary tree is: " << size << endl;

    return 0;
}


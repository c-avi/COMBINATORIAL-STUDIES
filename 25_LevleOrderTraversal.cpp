#include <iostream>
#include <queue>
using namespace std;

// Definition of Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to Build a Binary Tree from Level Order Input
TreeNode* buildTree() {
    int val;
    cout << "Enter root value: ";
    cin >> val;
    
    if (val == -1) return nullptr;  // Empty tree

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Function for Level Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level Order Traversal: ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Main function
int main() {
    TreeNode* root = buildTree();
    levelOrderTraversal(root);
    return 0;
}

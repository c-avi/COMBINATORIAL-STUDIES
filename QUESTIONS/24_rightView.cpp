#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree from level order input
Node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of" << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    } 
    return root;
}

// Right view function using level-order traversal
void printRightView(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* rightMost = nullptr;

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); q.pop();
            rightMost = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (rightMost)
            cout << rightMost->data << " ";
    }

}

int main() {
    Node* root = buildTree();

    cout << "Right view of the binary tree: ";
    printRightView(root);

    return 0;
}
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to print the top view
void topView(Node* root) {
    if (!root) return;

    // Map to store the first node at each horizontal distance
    map<int, int> topNodes;

    // Queue to hold pairs of node and itshorizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        Node* curr = p.first;
        int hd = p.second;

        // If the HD is being seen for the first time, store it 
        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = curr->data;
        }

        if (curr->left)
            q.push({curr->left, hd - 1});
        if(curr->right)
            q.push({curr->right, hd + 1});
    }
    // Print top view
    for (auto it : topNodes) {
        cout << it.second << " ";
    }
    cout << "\n";
}

// Helper function to build a sample tree
Node* buildSampleTree() {
    /*
      1
     /  \
    2    3
     \  / \
     4 5   6
     */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    return root; 
}

int main() {
    Node* root = buildSampleTree();
    cout << "Top view of the binary tree is : ";
    topView(root);
    return 0;
}
#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to print the bottom view
void bottomView(Node* root) {
    if (!root) return;

    // Map to store horizontal distance and corrsppnding node value
    map<int, int> hdMap; // {horizontal distance : node->data}
    queue<pair<Node*, int>> q; // Pair of Node and its horizontal distance

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* curr = front.first;
        int hd = front.second;

        // Update the map every time (this ensures bottom-most nodes overwrite top ones)
        hdMap[hd] = curr->data;

        if (curr->left) 
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

        // Print bottom view from leftmost to rightmost horizontal distance
        for (auto it : hdMap) 
            cout << it.second << " ";
        cout << "\n";
    
}

// Sample binary tree
/*
      20
      /\
     8 22
    /\   \
   5 3    25
     /\
   10 14
  */

  int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << "Bottom View of the Binary Tree: ";
    bottomView(root);

    return 0;
  }
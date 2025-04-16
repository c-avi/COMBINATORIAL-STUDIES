#include<iostream> 
#include<map>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

// Function to build the binary tree (level order)
Node* buildTree() {
    int val;
    cout << "Enter root value: ";
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

        cout << "Enter right child of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

// Function to print the top view
void topView(Node* root) {
    if (!root) return;

    // Map of HD to node data
    map<int, int> top;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();

        // Store first node at each HD
        if (top.find(hd) == top.end())
            top[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    cout << "\nTop View: ";
    for (auto it : top)
        cout << it.second << " ";
    cout << endl;
}

int main(){
    Node* root = buildTree();
    topView(root);
    return 0;
}
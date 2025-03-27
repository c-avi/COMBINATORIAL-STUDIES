#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// Function to display the linked list
void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }
    
    cout << "Original List: ";
    display(head);
    
    head = reverseList(head);
    
    cout << "Reversed List: ";
    display(head);
    
    return 0;
}

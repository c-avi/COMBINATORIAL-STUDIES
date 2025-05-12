#include <iostream>
using namespace std;

// Definition for singly linked list
struct Node{
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to find length of linked list
int findLength(Node* head) {
    int length = 0;
    Node* current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}

int main() {
    // Creating linked list : 2->3->4->1->5
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);

    // Finding length
    int length = findLength(head);

    cout << "Length of the linked list is: " << length << "\n";

    return 0;
}
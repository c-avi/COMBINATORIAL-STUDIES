#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp -> next;
    temp->next = new Node(val);
}

// Take input from user
Node* createList() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter number of digits: ";
    cin >> n;
    cout << "Enter digits (in reverse order, e.g., 3 4 2 for 243): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insert(head, val);
    }
    return head;
}

// Add two numbers represented by linked lists
Node* addLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) sum += l1->data, l1 = l1->next;
        if (l2) sum += l2->data, l2 = l2->next;
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    cout << "Create first number:\n";
    Node* l1 = createList();

    cout << "Create second number:\n";
    Node* l2 = createList();

    Node* result = addLists(l1, l2);

    cout << "Sum list (reversed order): ";
    printList(result);

    return 0;
}

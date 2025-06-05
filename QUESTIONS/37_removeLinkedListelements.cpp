#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class to remove elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to create linked list from user input
ListNode* createLinkedListFromInput(int n) {
    if (n == 0) return nullptr;

    int value;
    cout << "Enter value 1: ";
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* current = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter value " << i << ": ";
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    int n, valToRemove;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = createLinkedListFromInput(n);

    cout << "Enter the value to remove: ";
    cin >> valToRemove;

    cout << "Original List: ";
    printLinkedList(head);

    Solution solution;
    head = solution.removeElements(head, valToRemove);

    cout << "Updated List after removing " << valToRemove << ": ";
    printLinkedList(head);

    return 0;
}

#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int value) : val(value), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        ++size;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = node;
        }
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* node = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* toDelete = nullptr;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = current->next->next;
        }
        delete toDelete;
        --size;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    MyLinkedList myLinkedList;
    int choice, val, index;

    cout << "=== Singly Linked List Menu ===\n";
    do {
        cout << "\n1. Add at Head\n";
        cout << "2. Add at Tail\n";
        cout << "3. Add at Index\n";
        cout << "4. Get value at Index\n";
        cout << "5. Delete at Index\n";
        cout << "6. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at head: ";
                cin >> val;
                myLinkedList.addAtHead(val);
                break;
            case 2:
                cout << "Enter value to add at tail: ";
                cin >> val;
                myLinkedList.addAtTail(val);
                break;
            case 3:
                cout << "Enter index and value to add: ";
                cin >> index >> val;
                myLinkedList.addAtIndex(index, val);
                break;
            case 4:
                cout << "Enter index to get value: ";
                cin >> index;
                val = myLinkedList.get(index);
                if (val == -1)
                    cout << "Invalid index.\n";
                else
                    cout << "Value at index " << index << " is " << val << "\n";
                break;
            case 5:
                cout << "Enter index to delete: ";
                cin >> index;
                myLinkedList.deleteAtIndex(index);
                break;
            case 6:
                cout << "Current Linked List:\n";
                myLinkedList.printList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

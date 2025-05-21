#include <iostream>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 10007; // A prime number for better distribution
    struct Node {
        int key, value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    Node* data[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        for (int i = 0; i < SIZE; ++i) {
            data[i] = nullptr;
        }
    }

    void put(int key, int value) {
        int h = hash(key);
        Node* node = data[h];
        Node* prev = nullptr;
        while (node != nullptr) {
            if (node->key == key) {
                node->value = value; // update existing key
                return;
            }
            prev = node;
            node = node->next;
        }
        Node* newNode = new Node(key, value);
        if (prev == nullptr) {
            data[h] = newNode;
        } else {
            prev->next = newNode;
        }
    }

    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        while (node != nullptr) {
            if (node->key == key) return node->value;
            node = node->next;
        }
        return -1; // not found
    }

    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        Node* prev = nullptr;
        while (node != nullptr) {
            if (node->key == key) {
                if (prev == nullptr) {
                    data[h] = node->next;
                } else {
                    prev->next = node->next;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
};

int main() {
    MyHashMap myHashMap;

    myHashMap.put(1, 1);             // map: [[1,1]]
    myHashMap.put(2, 2);             // map: [[1,1], [2,2]]
    cout << myHashMap.get(1) << endl; // Output: 1
    cout << myHashMap.get(3) << endl; // Output: -1 (not found)
    myHashMap.put(2, 1);             // map: [[1,1], [2,1]] (update value)
    cout << myHashMap.get(2) << endl; // Output: 1
    myHashMap.remove(2);            // map: [[1,1]]
    cout << myHashMap.get(2) << endl; // Output: -1

    return 0;
}

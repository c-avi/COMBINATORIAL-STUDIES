#include <iostream>
using namespace std;

class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack() { top = -1; }

    void push(int x);
    int pop();
};

// Function to push an integer into the stack.
void MyStack::push(int x) {
    if (top < 999) { // check if there is space in the array
        top++;
        arr[top] = x;
    }
}

// Function to remove an item from top of the stack.
int MyStack::pop() {
    if (top == -1) {
        return -1; // stack is empty
    } else {
        int temp = arr[top];
        top--;
        return temp;
    }
}

// Driver code to read input queries and process them
int main() {
    MyStack stack;
    int input;
    while (cin >> input) {
        if (input == 1) {
            int x;
            cin >> x;
            stack.push(x);
        } else if (input == 2) {
            cout << stack.pop() << " ";
        }
    }
    return 0;
}

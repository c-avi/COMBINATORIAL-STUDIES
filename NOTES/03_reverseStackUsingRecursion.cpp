/*Write a program to reverse a stack using recursion, without using any loop.

Example: 

Input: elements present in stack from top to bottom 4 3 2 1
Output: 1 2 3 4*/
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.size() == 0) {
        s.push(x);
    } else {
        int a = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(a);
    }
}

void reverse(stack<int>& s) {
    if (s.size() > 0) {
        int x = s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s, x);
    }
}

int main() {
    stack<int> s;

    // Pushing elements to the stack : 4 3 2 1 (bottom to top)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Reversing the stack
    reverse(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
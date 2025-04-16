#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(top);
}

// Recursive function to reverse the stack
void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}
int main() {
    stack<int> st;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter stack elements (top to bottom):\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        st.push(x);
    }

    reverseStack(st);

    cout << "Reversed stck (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    return 0;
}
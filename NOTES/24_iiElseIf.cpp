#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter marks: ";
    cin >> m;

    if (m >= 90) cout << "Grade A";
    else if (m >= 70) cout << "Grade B";
    else if (m >= 50) cout << "Grade C";
    else if (m >= 35) cout << "Grade D";
    else cout << "Fail";
    return 0;
}
#include <iostream>
using namespace std;

void print(int n){
    if (n == 0){
        return;
    }
    cout << "Name\n";
    print(n-1);
}

int main(){
    int n;
    cout << "Enter the number of times you want to print the name: ";
    cin >> n;
    print(n);
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Function to convert any base (2 to 16) to decimal
int baseToDecimal(string num, int base) {
    int result = 0;
    int power = 0;

    for (int i = num.length() - 1; i >= 0; i--) {
        char digit = toupper(num[i]);
        int value;

        if (digit >= '0' && digit <= '9') 
            value = digit - '0';
        else if (digit >= 'A' && digit <= 'F')
            value = digit - 'A' + 10;
        else {
            cout << "Invalid character in number!\n";
            return -1;
        }

        if (value >= base) {
            cout << "Digit out of range for base " << base << "\n";
            return -1;
        }

        result += value * pow(base, power);
        power++;
    }

    return result;
}

// Function to convert decimal to other bases
string decimalToBase(int decimal, int base) {
    string result = "";
    string digits = "0123456789ABCDEF";

    if (decimal == 0)
        return "0";
    
    while (decimal > 0) {
        result = digits[decimal % base] + result;
        decimal /= base;
    }

    return result;

}

int main () {
    string inputNumber;
    int inputBase;

    cout << "Enter the number: ";
    cin >> inputNumber;
    cout << "Enter the base of the number (2 to 16): ";
    cin >> inputBase;

    if (inputBase < 2 || inputBase > 16) {
        cout << "Base must be between 2 and 16.\n";
        return 1;
    }

    int decimal = baseToDecimal(inputNumber, inputBase);
    if (decimal == -1)
        return 1; // Error in conversion

    cout << "\nConversion:\n";
    cout << "Decimal: " << decimal << "\n";
    cout << "Binary: " << decimalToBase(decimal, 2) << "\n";
    cout << "Octal: " << decimalToBase(decimal, 8) << "\n";
    cout << "Hexadecimal: " << decimalToBase(decimal, 16) << "\n";
    
    return 0;
    
}
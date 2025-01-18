#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int hexadecimalToDecimal(string hexNumber) {
    int decimalNumber = 0;
    int length = hexNumber.length();

    for (int i = 0; i < length; i++) {
        char hexDigit = hexNumber[length - 1 - i];
        int value;

        if (hexDigit >= '0' && hexDigit <= '9') {
            value = hexDigit - '0';
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            value = hexDigit - 'A' + 10;
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            value = hexDigit - 'a' + 10;
        } else {
            cout << "Invalid hexadecimal digit: " << hexDigit << endl;
            return -1;
        }

        decimalNumber += value * pow(16, i);
    }

    return decimalNumber;
}

int main() {
    string hexNumber;

    cout << "Enter a hexadecimal number: ";
    cin >> hexNumber;

    int decimalNumber = hexadecimalToDecimal(hexNumber);
    if (decimalNumber != -1) {
        cout << "Decimal number: " << decimalNumber << endl;
    }

    return 0;
}
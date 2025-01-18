#include <iostream>
using namespace std;

void decimalToHexadecimal(int decimalNumber) {
    char hexadecimalNumber[100];
    int i = 0;

    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10)
            hexadecimalNumber[i] = remainder + 48; // ASCII value of 0 is 48
        else
            hexadecimalNumber[i] = remainder + 55; // ASCII value of A is 65
        decimalNumber /= 16;
        i++;
    }

    cout << "Hexadecimal number: ";
    for (int j = i - 1; j >= 0; j--)
        cout << hexadecimalNumber[j];
    cout << endl;
}

int main() {
    int decimalNumber;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToHexadecimal(decimalNumber);

    return 0;
}
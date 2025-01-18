#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    return decimalNumber;
}

int main() {
    long long binaryNumber;

    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Decimal number: " << decimalNumber << endl;

    return 0;
}
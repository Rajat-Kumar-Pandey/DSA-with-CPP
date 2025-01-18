#include <iostream>
#include <cmath>
using namespace std;

int octalToDecimal(int octalNumber) {
    int decimalNumber = 0, i = 0;

    while (octalNumber != 0) {
        int remainder = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += remainder * pow(8, i);
        ++i;
    }

    return decimalNumber;
}

int main() {
    int octalNumber;

    cout << "Enter an octal number: ";
    cin >> octalNumber;

    int decimalNumber = octalToDecimal(octalNumber);
    cout << "Decimal number: " << decimalNumber << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void decimalToBinary(int n) {
    vector<int> binaryNum;

    // Loop to store binary representation
    while (n > 0) {
        binaryNum.push_back(n % 2);
        n = n / 2;
    }

    // Print binary representation in reverse order
    for (int i = binaryNum.size() - 1; i >= 0; i--)
        cout << binaryNum[i];
    cout << endl;
}

int main() {
    int num = 37;
    cout << "Binary representation of " << num << " is: ";
    decimalToBinary(num);
    return 0;
}

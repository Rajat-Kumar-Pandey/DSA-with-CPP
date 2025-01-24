#include <iostream>
using namespace std;

unsigned long long fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n;
    unsigned long long factorial;

    cout << "Enter a number to find factorial: ";
    cin >> n;
    factorial = fact(n);
    cout << "Factorial of " << n << " is " << factorial << endl;
    return 0;
}
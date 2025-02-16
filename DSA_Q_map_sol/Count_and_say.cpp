#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1"; // Base Case
    
    string result = "1"; // Start with the first term

    for (int i = 2; i <= n; i++) {  // Generate sequences iteratively
        string temp = "";  // Temporary string for new sequence
        int len = result.length();
        int count = 1;

        for (int j = 0; j < len; j++) {
            // If next character is same, increase count
            if (j + 1 < len && result[j] == result[j + 1]) {
                count++;
            } else {
                // Otherwise, append count and digit
                temp += to_string(count) + result[j];
                count = 1; // Reset count
            }
        }
        result = temp; // Update result for next iteration
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Count and Say (" << n << "): " << countAndSay(n) << endl;
    return 0;
}

/*
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
// Input: n = 4
// Output: Count and Say (4): 1211

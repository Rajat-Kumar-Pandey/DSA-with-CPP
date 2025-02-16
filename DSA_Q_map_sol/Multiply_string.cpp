// Correct Approach: Multiply Strings Without Overflow
// Since num1 and num2 can be very large, we need to implement multiplication manually, similar to how we multiply numbers on paper.

// Multiplication Logic
// Reverse Iteration: Multiply each digit of num1 with each digit of num2.
// Store Partial Results: Use an array res of size num1.length() + num2.length() to store intermediate values.
// Handle Carry: Keep track of carry while multiplying.
// Convert Array to String: Skip leading zeros and convert the array to a final result.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";  // Edge case: Multiplication with 0

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);  // Result array to store digits

        // Multiply each digit from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');  // Convert chars to digits
                int sum = mul + res[i + j + 1];  // Add to previous stored value
                
                res[i + j + 1] = sum % 10;  // Store unit place
                res[i + j] += sum / 10;  // Carry forward
            }
        }

        // Convert vector to string, skipping leading zeros
        string result = "";
        for (int num : res) {
            if (!(result.empty() && num == 0)) {  // Skip leading zeros
                result += to_string(num);
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    string num1, num2;
    cout << "Enter two large numbers: ";
    cin >> num1 >> num2;
    cout << "Product: " << sol.multiply(num1, num2) << endl;
    return 0;
}

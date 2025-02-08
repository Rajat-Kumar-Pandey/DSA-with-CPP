#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // Initialization
        int i = 0, n = s.length();
        long res = 0; // Use 'long' to handle overflow
        int sign = 1; // Default is positive

        // 1. Ignore leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            // 4. Check for overflow
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;
            
            i++;
        }

        // 5. Return the final integer
        return sign * res;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input); // Read full input including spaces
    
    int output = sol.myAtoi(input);
    cout << "Converted Integer: " << output << endl;

    return 0;
}


// Approach:
// 1. Initialize the index 'i' to 0 and the result 'res' to 0.
// 2. Ignore leading spaces by incrementing 'i' until 'i' is less than 'n' and 's[i]' is a space character.
// 3. Check the sign of the number by checking if 's[i]' is '+' or '-'.
//    - If it is '-', set 'sign' to -1, else set it to 1.
//    - Increment 'i'.
// 4. Read the digits of the number by iterating until 'i' is less than 'n' and 's[i]' is a digit.
//    - Update 'res' by multiplying it by 10 and adding the current digit.
//    - Check for overflow by comparing 'sign * res' with INT_MAX and INT_MIN.
//    - Increment 'i'.
// 5. Return the final integer by multiplying 'res' with 'sign'.

// Complexity Analysis:
// - Time complexity: O(n)
//   We iterate through the string 's' of length 'n' once.
// - Space complexity: O(1)
//   We use only a constant amount of extra space.

// Input:
// Enter a string: 42
// Output:
// Converted Integer: 42
// Explanation:
// The input string is "42", which represents the integer 42.
// The function correctly converts this string to the integer 42.

// Input:
// Enter a string: -42
// Output:
// Converted Integer: -42
// Explanation:
// The input string is "-42", which represents the integer -42.
// The function correctly converts this string to the integer -42.

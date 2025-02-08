// Flowchart
// Steps
// Start
// Initialize longest = ""
// Loop over each character index i:
// Expand around i (odd-length palindrome).
// Expand around i, i+1 (even-length palindrome).
// Update longest if a longer palindrome is found.
// Return longest
// End

// Flowchart Representation

//           Start
//             |
//       Initialize longest = ""
//             |
//       Iterate over each index i
//             |
//      Expand from (i, i)  → Odd-length palindrome
//             |
//      Expand from (i, i+1) → Even-length palindrome
//             |
//      Update longest substring
//             |
//      Continue until i < s.length()
//             |
//         Return longest
//             |
//           End




#include <iostream>
using namespace std;

class Solution {
public:
    string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            string odd = expandFromCenter(s, i, i);   // Odd-length palindrome
            string even = expandFromCenter(s, i, i + 1);  // Even-length palindrome

            if (odd.length() > longest.length()) longest = odd;
            if (even.length() > longest.length()) longest = even;
        }
        return longest;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    Solution solution;
    cout << "Longest Palindromic Substring: " << solution.longestPalindrome(s) << endl;

    return 0;
}
// Complexity Analysis
// Time Complexity: O(n^2) (Each character is processed twice)
// Space Complexity: O(1) (No extra space used)

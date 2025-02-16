// Key Constraints for a Valid IP Address
// The IP address must have 4 parts separated by dots.
// Each part must be between 0 and 255 (inclusive).
// Each part cannot have leading zeros unless it is "0" itself.


// Best Approach: Backtracking
// Why Use Backtracking?
// We must try all possible ways of placing three dots (.) in the string while ensuring validity.
// Since each segment can be 1 to 3 digits long, a brute force approach would be inefficient.
// Backtracking helps efficiently explore all valid possibilities and backtrack when an invalid condition is met.
// Algorithm
// Define a backtracking function that:

// Takes the start index and current segments as parameters.
// If we reach four segments and the entire string is used, store the result.
// If we have four segments but haven't used the entire string, return early.
// Try 1-digit, 2-digit, and 3-digit segments while checking validity.
// Recursively call the function with the next index.
// Check for validity:

// The number must be in [0, 255].
// No leading zeros unless it is "0".

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &s, int index, vector<string> &current, vector<string> &result) {
        if (current.size() == 4) {  // IP address must have exactly 4 parts
            if (index == s.length()) {
                result.push_back(join(current));  // Add valid IP to result
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {  // Try lengths 1, 2, and 3
            if (index + len > s.length()) break;  // Out of bounds check
            string part = s.substr(index, len);  // Extract substring

            if (isValid(part)) {  // Check validity
                current.push_back(part);  // Choose
                backtrack(s, index + len, current, result);  // Explore
                current.pop_back();  // Undo choice (backtrack)
            }
        }
    }

    bool isValid(const string &part) {
        if (part.length() > 1 && part[0] == '0') return false;  // Leading zero case
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    string join(const vector<string> &parts) {
        return parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
    }
};

// Driver Code
int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;
    vector<string> result = sol.restoreIpAddresses(s);
    cout << "Valid IPs: \n";
    for (const string &ip : result) {
        cout << ip << endl;
    }
    return 0;
}


// Time & Space Complexity Analysis
// Time Complexity: O(1)
// The maximum number of valid IP addresses is at most 2^12 = 4096 (since a valid IP has at most 12 characters).
// We prune invalid cases early, reducing unnecessary recursion.
// O(1) (constant) complexity since we only generate a finite number of results.
// Space Complexity: O(1)
// At most O(20) for storing recursive calls and results.
// Since the number of valid IPs is limited, the space usage is constant.

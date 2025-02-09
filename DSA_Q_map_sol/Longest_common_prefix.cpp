// APPORACH : Binary Search (Optimized)
// Idea:

// Find the minimum string length in strs, set it as the search range [low, high].
// Perform binary search on prefix length:
// Check if all strings share a prefix of mid length.
// If yes, increase low, otherwise decrease high.

#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

class Solution {
public:
    // Function to find the longest common prefix using Binary Search
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int minl = INT_MAX;  // Find the shortest string length
        for (const string &str : strs) {
            minl = min(minl, (int)str.size());
        }

        int l = 0, h = minl;
        while (l <= h) {  // Binary search
            int mid = l + (h - l) / 2;
            if (isCommonPrefix(strs, mid)) {
                l = mid + 1;  // Try for a longer prefix
            } else {
                h = mid - 1;  // Reduce the search space
            }
        }
        return strs[0].substr(0, h);  // Return the longest common prefix
    }

private:
    // Helper function to check if a prefix of given length is common to all strings
    bool isCommonPrefix(vector<string>& strs, int length) {
        string prefix = strs[0].substr(0, length);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].substr(0, length) != prefix) return false;
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution sol;
    string result = sol.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: \"" << result << "\"" << endl;
    return 0;
}

// Time Complexity: O(S * log(minLen)), where S is the sum of all characters in all strings
// Space Complexity: O(1)

// Testcase:
// Input:
// Enter the number of strings: 3
// Enter the strings:
// flower
// flow
// flight
// Output:
// Longest Common Prefix: "fl"
// Explanation: The longest common prefix is "fl" which is common to all the strings.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle); // Find the first occurrence of needle in haystack
        return (pos != string::npos) ? static_cast<int>(pos) : -1; // Return the index or -1 if not found
    }
};

int main() {
    string haystack, needle;
    
    // Taking user input for haystack and needle
    cout << "Enter the haystack string: ";
    getline(cin, haystack);
    
    cout << "Enter the needle string: ";
    getline(cin, needle);
    
    Solution solution; 
    int result = solution.strStr(haystack, needle);
    
    cout << "Output: " << result << endl;

    return 0;
}
// Complexity Analysis:
// Time Complexity: O(N * M), where N and M are the lengths of the haystack and needle strings, respectively.
// Space Complexity: O(1).

// Testcases:
// Input: haystack = "hello", needle = "ll"
// Output: 2
// Explanation: The needle "ll" is found in the haystack string at index 2.
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Explanation: The needle "bba" is not found in the haystack string.
// Approach
// Use two pointers (left and right) to represent the window.
// Expand right to include new characters while ensuring all characters are unique.
// If a character repeats, move left forward to remove duplicate characters.
// Maintain the maximum window size encountered.

// Pseudocode
//     Initialize hash_map to store character indices
//     Initialize left = 0, max_length = 0

//     For right from 0 to length of s:
//         If s[right] is in hash_map:
//             Move left to max(left, hash_map[s[right]] + 1)

//         Update hash_map[s[right]] = right
//         max_length = max(max_length, right - left + 1)

//     Return max_length


// Flowchart Representation
// Start
// |
// Initialize
// (hash_map, left = 0, max_length = 0)
// |
// For each character
// |
// Check if char in hash_map
// /              \
// Yes               No
// |                |
// Update left      Update hash_map[s[right]]
// |                |
// Update hash_map  Update max_length
// |                |
// Continue loop    Continue loop
// |
// Return max_length
// |
// End

// Complexity Analysis
// Time Complexity: O(n) (Each character is processed at most twice)
// Space Complexity: O(min(n,256)) (Using hash_map for 256 ASCII characters)


#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeating(string s) {
    unordered_map<char, int> hash_map;
    int left = 0, max_length = 0;

    for (int right = 0; right < s.length(); right++) {
        if (hash_map.find(s[right]) != hash_map.end()) {
            left = max(left, hash_map[s[right]] + 1);
        }

        hash_map[s[right]] = right;
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}
int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    cout << "Length of longest substring without repeating characters: "
         << longestSubstringWithoutRepeating(s) << endl;
    return 0;
}

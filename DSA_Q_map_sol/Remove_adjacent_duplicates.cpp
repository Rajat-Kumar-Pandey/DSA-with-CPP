// Algorithm
// Create an empty stack (implemented using a string in C++).
// Iterate over the input string:
// If the stack is not empty and the top of the stack equals the current character, pop it (removal of duplicates).
// Otherwise, push the character onto the stack.
// After processing all characters, the stack contains the final string without duplicates.
// Convert the stack to a string and return it.



#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string stack;  // Using string as a stack

        for (char ch : s) {
            if (!stack.empty() && stack.back() == ch) {
                stack.pop_back();  // Remove adjacent duplicate
            } else {
                stack.push_back(ch);  // Add character to stack
            }
        }
        
        return stack;  // Stack now contains the final result
    }
};

// Driver Code
int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Final String after duplicate removals: " << sol.removeDuplicates(s) << endl;
    return 0;
}




// Time and Space Complexity Analysis
// Time Complexity: 🚀 O(N)
// Each character is pushed once and popped at most once, leading to an O(N) time complexity.
// N is the length of the string.
// Space Complexity: ✅ O(N) (Worst Case)
// In the worst case, no duplicates are removed, and the stack stores all characters.
// If all characters are removed, space usage is O(1).
// Overall, O(N) space complexity is required in the worst case.
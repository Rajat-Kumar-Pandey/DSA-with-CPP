// To solve this problem, we can use a stack data structure. The stack follows the Last In, First Out (LIFO) principle, which helps maintain the order of opening and closing brackets.

// Approach
// Use a stack to store opening brackets.
// Traverse the string character by character:
// If it's an opening bracket ((, {, [), push it onto the stack.
// If it's a closing bracket (), }, ]):
// Check if the stack is empty (if empty, return false).
// Check if the top of the stack has the matching opening bracket.
// If matched, pop the top element from the stack.
// If not matched, return false.
// After traversal, if the stack is empty, return true, otherwise return false.
// Flowchart
// plaintext
// Copy
// Edit
// Start
//   ↓
// Initialize an empty stack
//   ↓
// For each character in the string:
//   ↓
//   If it is an opening bracket:
//     Push it onto the stack
//   ↓
//   Else if it is a closing bracket:
//     If stack is empty → Return false
//     Else:
//       Check top of stack
//       If it matches the corresponding opening bracket → Pop the stack
//       Else → Return false
//   ↓
// If stack is empty → Return true
// Else → Return false
//   ↓
// End


#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> bracketMap = { {')', '('}, {'}', '{'}, {']', '['} };

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != bracketMap[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    
    if (isValid(s)) {
        cout << "Valid Parentheses\n";
    } else {
        cout << "Invalid Parentheses\n";
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)

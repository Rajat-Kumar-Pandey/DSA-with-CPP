#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int m = s.length(), n = t.length();
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == m;
}

int main() {
    // Example usage:
    string s1 = "abc", t1 = "ahbgdc";
    cout << isSubsequence(s1, t1) << endl; // Output: 1 (true)

    string s2 = "axc", t2 = "ahbgdc";
    cout << isSubsequence(s2, t2) << endl; // Output: 0 (false)

    return 0;
}

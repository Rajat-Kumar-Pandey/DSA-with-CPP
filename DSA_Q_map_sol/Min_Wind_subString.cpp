#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tFreq(128, 0), windowFreq(128, 0);
        for (char c : t) tFreq[c]++;

        int left = 0, right = 0, minLen = INT_MAX, startIdx = 0;
        int required = t.size(), formed = 0;

        while (right < s.size()) {
            char c = s[right];
            if (tFreq[c] > 0) {
                windowFreq[c]++;
                if (windowFreq[c] <= tFreq[c]) formed++;
            }

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (tFreq[leftChar] > 0) {
                    if (windowFreq[leftChar] == tFreq[leftChar]) formed--;
                    windowFreq[leftChar]--;
                }

                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};

int main() {
    string s, t;
    
    // Taking user input
    cout << "Enter the main string (s): ";
    cin >> s;
    
    cout << "Enter the target string (t): ";
    cin >> t;

    Solution obj;
    string result = obj.minWindow(s, t);
    
    cout << "Minimum window substring: " << (result.empty() ? "No valid window found" : result) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    // Iterate over each word in the given list
    for (string s : strs) {
        string sortedWord = s;
        sort(sortedWord.begin(), sortedWord.end()); // Sort the word to get the key
        anagramGroups[sortedWord].push_back(s);  // Store the original word under the key
    }

    // Collect the grouped anagrams
    vector<vector<string>> result;
    for (auto group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}

// Driver code
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    // Print result
    for (auto group : result) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}


// Time Complexity: O(N * K * log K), where N is the number of strings in the input list and K is the maximum length of a string in the list.
// Space Complexity: O(N * K), where N is the number of strings in the input list and K is the maximum length of a string in the list.
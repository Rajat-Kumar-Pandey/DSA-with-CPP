#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, int> last_occurrence;
    vector<int> partitions;

    // Step 1: Record the last occurrence of each character
    for (int i = 0; i < s.length(); i++) {
        last_occurrence[s[i]] = i;
    }

    // Step 2: Partition the string
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        end = max(end, last_occurrence[s[i]]);
        if (i == end) {
            partitions.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return partitions;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<int> result = partitionLabels(s);
    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
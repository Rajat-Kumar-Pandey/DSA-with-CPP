class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return accumulate(word1.begin(), word1.end(), string()) == 
               accumulate(word2.begin(), word2.end(), string());
    }
};

int main() {
    Solution solution;
    int n, m;
    cout << "Enter the number of strings in the first array: ";
    cin >> n;
    vector<string> word1(n);
    cout << "Enter the strings in the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> word1[i];
    }
    cout << "Enter the number of strings in the second array: ";
    cin >> m;
    vector<string> word2(m);
    cout << "Enter the strings in the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> word2[i];
    }
    if (solution.arrayStringsAreEqual(word1, word2)) {
        cout << "The concatenated strings are equal." << endl;
    } else {
        cout << "The concatenated strings are not equal." << endl;
    }
    return 0;
}
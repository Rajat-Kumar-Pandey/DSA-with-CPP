// Understanding the Problem Statement
// Flow of code
//             START
//                |
//            Sort the citations array in descending order
//                |
//            Initialize h = 0
//                |
//           Iterate through the sorted array
//                |
//          Check if citations[i] >= (i+1)
//          If true, update h to (i+1)
//                |
//            Else, break the loop
//                |
//              Output h
//                |
//             END
// End of code flow

// Time & Space Complexity Analysis
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) for sorting
// Where n is the number of citations
// End of Time & Space Complexity Analysis
// End of code
// End of code explanation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int h = 0;

    cout << "[DEBUG] Sorted citations: ";
    for (int citation : citations) {
        cout << citation << " ";
    }
    cout << endl;

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h = i + 1;
            cout << "[DEBUG] citations[" << i << "] = " << citations[i] << " is >= " << i + 1 << ", updating h to " << h << endl;
        } else {
            cout << "[DEBUG] citations[" << i << "] = " << citations[i] << " is < " << i + 1 << ", breaking the loop" << endl;
            break;
        }
    }

    return h;
}

int main() {
    int n;
    cout << "Enter the number of citations: ";
    cin >> n;

    vector<int> citations(n);
    cout << "Enter the citations: ";
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    int result = hIndex(citations);
    cout << "The H-Index is: " << result << endl;

    return 0;
}


// Output
// G:\dsa_c++\DSA_Q_map_sol>program                   
// Enter the number of citations: 5
// Enter the citations: 3 0 6 1 5 
// [DEBUG] Sorted citations: 6 5 3 1 0 
// [DEBUG] citations[0] = 6 is >= 1, updating h to 1
// [DEBUG] citations[1] = 5 is >= 2, updating h to 2
// [DEBUG] citations[2] = 3 is >= 3, updating h to 3
// [DEBUG] citations[3] = 1 is < 4, breaking the loop
// The H-Index is: 3
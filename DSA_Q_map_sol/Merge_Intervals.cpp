#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (merged.back()[1] >= intervals[i][0]) {
            // If intervals overlap, merge them
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // If they don't overlap, add the interval to the result
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start and end): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> result = merge(intervals);
    cout << "Merged intervals: " << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}
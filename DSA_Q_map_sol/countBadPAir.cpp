// Key Idea:
// If new_val[i] has appeared freq times before, then all freq previous indices form good pairs with i.
// Total pairs possible up to i = i
// Good pairs = freq
// Bad pairs = i - freq
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countBadPairs(vector<int>& nums) {
    long long n = nums.size();
    long long totalPairs = (n * (n - 1)) / 2;  // Total pairs (i, j) where i < j
    unordered_map<int, long long> freqMap;
    long long goodPairs = 0;

    for (int i = 0; i < n; i++) {
        int key = nums[i] - i;
        goodPairs += freqMap[key];  // Count how many times key appeared before
        freqMap[key]++;             // Update frequency
    }

    return totalPairs - goodPairs;
}

int main() {
    vector<int> nums = {4,1,3,3};
    cout << countBadPairs(nums) << endl; // Output: 5
}

// Time Complexity: O(N)
// Space Complexity: O(N)

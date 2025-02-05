// To solve this problem in O(n) time complexity, we can use HashSet-based approach instead of sorting (which would take O(n log n)).
//
// Approach:
//     Insert all elements into a HashSet (for O(1) lookups).
//     Iterate through the array and check if a number is the start of a sequence (i.e., num - 1 is not present in the set).
//     If it's the start, expand the sequence by checking for num + 1, num + 2, ... until the sequence ends.
//     Keep track of the longest sequence length found.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        // Check if it's the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int count = 1;

            // Expand the sequence
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Output: " << longestConsecutive(nums1) << endl; // Expected Output: 4

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Output: " << longestConsecutive(nums2) << endl; // Expected Output: 9

    return 0;
}

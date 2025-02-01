// Find the maximum number of consecutive 1s in a binary array

#include <iostream>
#include <vector>
#include <algorithm>  // For max() function

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxcount = 0;

        cout << "Processing array: ";
        for (int num : nums) cout << num << " ";
        cout << endl;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;  
                maxcount = max(maxcount, count);  // Update max consecutive ones
            } else {
                cout << "Encountered 0 at index " << i << ", resetting count.\n";
                count = 0;  // Reset count when encountering zero
            }

            // Debugging output for each step
            cout << "Index: " << i << ", Current Number: " << nums[i] 
                 << ", Current Count: " << count << ", Max Count: " << maxcount << endl;
        }

        return maxcount;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " binary numbers (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = solution.findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}

// Sample Input/Output:
// Enter number of elements in the array: 8
// Enter 8 binary numbers (0s and 1s): 1 0 1 1 0 1 1 1
// Processing array: 1 0 1 1 0 1 1 1
// Index: 0, Current Number: 1, Current Count: 1, Max Count: 1
// Index: 1, Current Number: 0, Current Count: 0, Max Count: 1
// Encountered 0 at index 1, resetting count.
// Index: 2, Current Number: 1, Current Count: 1, Max Count: 1
// Index: 3, Current Number: 1, Current Count: 2, Max Count: 2
// Index: 4, Current Number: 0, Current Count: 0, Max Count
// Encountered 0 at index 4, resetting count.
// Index: 5, Current Number: 1, Current Count: 1, Max Count: 2
// Index: 6, Current Number: 1, Current Count: 2, Max Count: 2
// Index: 7, Current Number: 1, Current Count: 3, Max Count: 3
// Maximum consecutive 1s: 3
//
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1).

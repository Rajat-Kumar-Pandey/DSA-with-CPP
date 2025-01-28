// Sliding Window Technique (O(n) Solution)

// Algorithm Steps

// Initialize two pointers: left (start of the window) and right (end of the window).
// Maintain a variable current_sum to track the sum of the current window.
// Expand the window by moving the right pointer and adding nums[right] to current_sum.
// If current_sum becomes greater than or equal to target, try shrinking the window from the left (left pointer) while maintaining the condition.
// Keep track of the minimal window size during this process.
// Return the minimal window size. If no valid subarray is found, return 0.


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int current_sum = 0;
    int min_length = INT_MAX;

    for (int right = 0; right < n; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            min_length = min(min_length, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    return (min_length == INT_MAX) ? 0 : min_length;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    int result = minSubArrayLen(target, nums);
    if (result != 0) {
        cout << "The minimum size subarray with sum >= " << target << " is: " << result << endl;
    } else {
        cout << "No valid subarray found." << endl;
    }

    return 0;
}
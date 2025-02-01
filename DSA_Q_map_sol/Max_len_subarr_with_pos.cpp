// We are given an array of integers, and we need to find the maximum length of a subarray where the product of all its elements is positive.

// Logical Approach
// We can traverse the array while keeping track of:

// The length of the current valid subarray.
// The number of negative numbers in the subarray.
// Handling zeros (resetting when we encounter a zero).
// To efficiently track these, we can use:

// posLength: The length of the longest subarray ending at the current index where the product is positive.
// negLength: The length of the longest subarray ending at the current index where the product is negative.
// Reset both counters when encountering zero.
// Swap values when encountering a negative number.
// Flow of the code
//      Start
//        ↓
//    Initialize posLength = 0, negLength = 0, maxLen = 0
//        ↓
//    For each num in nums:
//        ↓
//    If num == 0:
//        Reset posLength and negLength
//        ↓
//    Else if num > 0:
//        Increment posLength
//        Increment negLength if negLength > 0
//        ↓
//    Else (num < 0):
//        Swap posLength and negLength
//        Increment negLength
//        Increment posLength if posLength > 0
//        ↓
//    Update maxLen
//        ↓
//    End of Loop
//        ↓
//    Return maxLen

#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum length of subarray with positive product
int maxLengthSubarray(vector<int>& nums) {
    int posLength = 0, negLength = 0, maxLen = 0;

    cout << "\nDebugging Output:\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        // If we encounter zero, reset both lengths
        if (num == 0) {
            cout << "nums[" << i << "] = " << num << " (Zero found) -> Reset posLength and negLength\n";
            posLength = 0;
            negLength = 0;
        } 
        else if (num > 0) {  // Positive number
            posLength++;
            if (negLength > 0) negLength++;
            cout << "nums[" << i << "] = " << num << " (Positive) -> posLength = " << posLength 
                 << ", negLength = " << negLength << "\n";
        } 
        else {  // Negative number
            swap(posLength, negLength);
            negLength++;
            if (posLength > 0) posLength++;
            cout << "nums[" << i << "] = " << num << " (Negative) -> posLength = " << posLength 
                 << ", negLength = " << negLength << " (Swapped & Updated)\n";
        }

        maxLen = max(maxLen, posLength);
    }

    cout << "--------------------------------\n";
    return maxLen;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxLengthSubarray(nums);
    cout << "\nMaximum Length of Subarray with Positive Product: " << result << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// Example 1:
// Input: nums = {1, -2, -3, 4}
// Output: 4
// Explanation: The subarray [1, -2, -3, 4] has a positive product.
// Example 2:
// Input: nums = {0, 1, -2, -3, -4}
// Output: 3
// Explanation: The subarray [1, -2, -3] has a positive product.

// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter the number of elements in the array: 5
// Enter 5 integers: -1 9 -2 8 -3

// Debugging Output:
// --------------------------------
// nums[0] = -1 (Negative) -> posLength = 0, negLength = 1 (Swapped & Updated)
// nums[1] = 9 (Positive) -> posLength = 1, negLength = 2
// nums[2] = -2 (Negative) -> posLength = 3, negLength = 2 (Swapped & Updated)
// nums[3] = 8 (Positive) -> posLength = 4, negLength = 3
// nums[4] = -3 (Negative) -> posLength = 4, negLength = 5 (Swapped & Updated)
// --------------------------------

// Maximum Length of Subarray with Positive Product: 4

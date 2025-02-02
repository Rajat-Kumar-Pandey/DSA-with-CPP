#include <iostream>
#include <vector>

using namespace std;

/**
 * Approach 1: XOR Method
 * - Uses the property: a ⊕ a = 0 and a ⊕ 0 = a.
 * - We XOR all numbers from 0 to n.
 * - We XOR all elements in the given array.
 * - The missing number is obtained by XORing these two results.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int missingNumber_XOR(vector<int>& nums) {
    int n = nums.size();
    int xor_all = 0, xor_nums = 0;

    // XOR all numbers from 0 to n
    for (int i = 0; i <= n; i++) {
        xor_all ^= i;
    }

    // XOR all elements in nums
    for (int num : nums) {
        xor_nums ^= num;
    }

    return xor_all ^ xor_nums;
}

/**
 * Approach 2: Summation Formula
 * - Uses the formula for the sum of first `n` natural numbers: Sum = (n * (n + 1)) / 2
 * - Computes expected sum and actual sum.
 * - The missing number is obtained by: Missing = Expected Sum - Actual Sum
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int missingNumber_Sum(vector<int>& nums) {
    int n = nums.size();
    int expected_sum = (n * (n + 1)) / 2; // Formula for sum of first n natural numbers
    int actual_sum = 0;

    // Calculate the actual sum of elements in nums
    for (int num : nums) {
        actual_sum += num;
    }

    return expected_sum - actual_sum;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << "Missing Number using XOR Method: " << missingNumber_XOR(nums) << endl;
    cout << "Missing Number using Summation Method: " << missingNumber_Sum(nums) << endl;

    return 0;
}

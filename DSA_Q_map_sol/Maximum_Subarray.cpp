#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxCurrent = nums[0];
    int maxGlobal = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        maxCurrent = max(nums[i], maxCurrent + nums[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }

    return maxGlobal;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxSum = maxSubArray(nums);
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
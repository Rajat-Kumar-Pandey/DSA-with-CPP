#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // To handle the case when subarray starts from index 0
    int currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }
        prefixSumCount[currentSum]++;
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum k: ";
    cin >> k;

    int result = subarraySum(nums, k);
    cout << "The total number of subarrays whose sum equals to " << k << " is: " << result << endl;

    return 0;
}
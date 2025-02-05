#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int minNum = INT_MAX, maxNum = INT_MIN;
    for (int num : nums) {
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }
    
    if (minNum == maxNum) return 0;  // If all elements are the same

    // Bucket size and count
    int bucketSize = max(1, (maxNum - minNum) / (n - 1));
    int bucketCount = (maxNum - minNum) / bucketSize + 1;

    // Buckets: each stores min and max value
    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    vector<bool> bucketUsed(bucketCount, false);

    // Place numbers into buckets
    for (int num : nums) {
        int idx = (num - minNum) / bucketSize;
        bucketMin[idx] = min(bucketMin[idx], num);
        bucketMax[idx] = max(bucketMax[idx], num);
        bucketUsed[idx] = true;
    }

    // Compute the maximum gap
    int maxGap = 0, prevMax = minNum;
    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;
        maxGap = max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return maxGap;
}

int main() {
    vector<int> nums1 = {3, 6, 9, 1};
    cout << "Output: " << maximumGap(nums1) << endl; // Expected Output: 3

    vector<int> nums2 = {10};
    cout << "Output: " << maximumGap(nums2) << endl; // Expected Output: 0

    return 0;
}



// or 

// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         int n = nums.size();
//         int dif = 0;

//         if(n <=1){
//             return 0;
//         }

//         sort(nums.begin(),nums.end());

//         for(int i = 1 ; i <n ; i++){
//             if(nums[i]-nums[i-1]> dif){
//                 dif = max(dif,nums[i]-nums[i-1]);
//             }

//         }
//         return dif;
//     }
// };
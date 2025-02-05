// Understanding the Problem
//     We need to find a subarray (contiguous elements) of at least length 2 whose sum is a multiple of k.

// Observations
//     Direct Sum Approach (Brute Force)
//         Iterate over all possible subarrays.
//         Calculate the sum and check if it’s a multiple of k.
//         Time Complexity: O(N^2) (Not efficient for large N).
//         Pseudocode :
//         FOR i FROM 0 TO N-1
//             FOR j FROM i+1 TO N-1
//                 sum = 0
//                 FOR k FROM i TO j
//                     sum += arr[k]
//                 IF sum % k == 0
//                     RETURN True


//     Using Prefix Sum with Modulo
//         If prefix_sum[j] % k == prefix_sum[i] % k for some i < j,
//         then the subarray sum from i+1 to j is a multiple of k.
//         Time Complexity: O(N) (Efficient).
//         Uses a HashMap (storing prefix sum mod k).

//         Pseudocode :
//             prefix_sum = 0
//             hashmap = new HashMap()
//             FOR i FROM 0 TO N-1
//                 prefix_sum += arr[i]
//                 remainder = prefix_sum % k
//                 IF remainder IN hashmap
//                     RETURN True
//                 ELSE
//                     hashmap[remainder] = i

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1;  // Handle cases where the sum itself is a multiple of k
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int remainder = sum % k;

        // Handle negative remainder
        if (remainder < 0) {
            remainder += k;
        }

        if (remainderIndex.find(remainder) != remainderIndex.end()) {
            if (i - remainderIndex[remainder] > 1) {
                return true;
            }
        } else {
            remainderIndex[remainder] = i;
        }
    }

    return false;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    cout << (checkSubarraySum(nums, k) ? "true" : "false") << endl;
    return 0;
}

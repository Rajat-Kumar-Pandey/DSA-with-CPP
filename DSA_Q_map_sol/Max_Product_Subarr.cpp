// Function maxProduct(nums):
//     if nums is empty:
//         return 0
    
//     Initialize max_prod = nums[0]
//     Initialize min_prod = nums[0]
//     Initialize result = nums[0]
    
//     for i from 1 to length of nums - 1:
//         If nums[i] is negative:
//             Swap max_prod and min_prod
            
//         max_prod = max(nums[i], max_prod * nums[i])
//         min_prod = min(nums[i], min_prod * nums[i])
        
//         result = max(result, max_prod)
    
//     return result


// Explanation:
// Initialize the variables: Start by setting max_prod, min_prod, and result to the first element of the array because at least one element must be considered.
// Iterate through the array: For each element, you check if it is negative. If it is, swapping max_prod and min_prod ensures that we correctly handle the negative product.
// Update max_prod and min_prod: For each element, update the max_prod to be the maximum between the current element and the product of the current element and the previous max_prod. Similarly, update the min_prod.
// Update the result: Keep track of the largest product found so far.
// Return the result: After processing all elements, return the result.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_prod = nums[0];
    int min_prod = nums[0];
    int result = nums[0];

    cout << "Initial max_prod: " << max_prod << ", min_prod: " << min_prod << ", result: " << result << endl;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(max_prod, min_prod);
            cout << "Swapped max_prod and min_prod due to negative number at index " << i << endl;
        }

        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);

        result = max(result, max_prod);

        cout << "Index: " << i << ", nums[i]: " << nums[i] << ", max_prod: " << max_prod << ", min_prod: " << min_prod << ", result: " << result << endl;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << "The maximum product subarray is: " << result << endl;

    return 0;
}



// Output:
// Enter the number of elements: 5
// Enter the elements of the array: -1 0 2 3 -2
// Initial max_prod: -1, min_prod: -1, result: -1
// Index: 1, nums[i]: 0, max_prod: 0, min_prod: 0, result: 0
// Index: 2, nums[i]: 2, max_prod: 2, min_prod: 0, result: 2
// Index: 3, nums[i]: 3, max_prod: 6, min_prod: 0, result: 6
// Swapped max_prod and min_prod due to negative number at index 4
// Index: 4, nums[i]: -2, max_prod: 0, min_prod: -12, result: 6
// The maximum product subarray is: 6
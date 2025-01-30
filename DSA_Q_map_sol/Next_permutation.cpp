// Find pivot: Traverse from right and find first decreasing element.
// Find next greater: Find the element just greater than pivot.
// Swap them.
// Reverse the suffix

//        Start
//          │
//          ▼
//    Find the pivot
//    (First decreasing element
//    from the right)
//          │
//          ▼
//    If no pivot found
//   (Array is largest perm.)
//         │Yes
//         ▼
//   Sort array in ascending
//         │
//        No
//         ▼
//    Find element just
//   larger than pivot
//         │
//         ▼
//     Swap pivot and found
//        larger element
//         │
//         ▼
//   Reverse suffix (right part)
//         │
//         ▼
//        End


#include <iostream>
#include <vector>
#include <algorithm> // For swap and reverse

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i, j;

    cout << "\n[DEBUG] Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // Step 1: Find the pivot (first decreasing element from right)
    for (i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            cout << "[DEBUG] Pivot found at index " << i << " with value " << nums[i] << endl;
            break;
        }
    }

    if (i >= 0) {  // If pivot is found
        // Step 2: Find the next greater element to pivot
        for (j = n - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                cout << "[DEBUG] Next greater element found at index " << j << " with value " << nums[j] << endl;
                break;
            }
        }
        // Step 3: Swap pivot and next greater element
        cout << "[DEBUG] Swapping " << nums[i] << " and " << nums[j] << endl;
        swap(nums[i], nums[j]);
    }
    
    // Step 4: Reverse the suffix (right part)
    cout << "[DEBUG] Reversing suffix from index " << i + 1 << " to end\n";
    reverse(nums.begin() + i + 1, nums.end());

    cout << "[DEBUG] Array after next permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
}

// Utility function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    // User input
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);  // Correctly initialize vector

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // Taking user input properly
    }

    cout << "Original array: ";
    printArray(nums);

    nextPermutation(nums);

    cout << "Next permutation: ";
    printArray(nums);

    return 0;
}


// G:\dsa_c++\build\Debug>outDebug.exe
// Enter the number of elements: 5
// Enter the elements: 4 5 3 2 1
// Original array: 4 5 3 2 1 

// [DEBUG] Original array: 4 5 3 2 1
// [DEBUG] Pivot found at index 0 with value 4
// [DEBUG] Next greater element found at index 1 with value 5
// [DEBUG] Swapping 4 and 5
// [DEBUG] Reversing suffix from index 1 to end
// [DEBUG] Array after next permutation: 5 1 2 3 4
// Next permutation: 5 1 2 3 4
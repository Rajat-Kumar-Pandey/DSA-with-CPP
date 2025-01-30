// The array is sorted but rotated, meaning there exists a pivot index where the order is broken.
// The pivot divides the array into two sorted subarrays: one part is strictly increasing, and the other wraps around.
// We can determine which half is sorted and decide whether to search in that half.



// Start
//   │
//   │--> Set left = 0, right = n - 1
//   │
//   │--> While (left <= right)
//   │      │
//   │      │--> mid = (left + right) / 2
//   │      │
//   │      │--> If nums[mid] == target → Return mid
//   │      │
//   │      │--> If nums[left] <= nums[mid] (Left half sorted?)
//   │      │      │
//   │      │      │--> If nums[left] <= target < nums[mid]
//   │      │      │       │--> Move right = mid - 1
//   │      │      │
//   │      │      │--> Else Move left = mid + 1
//   │      │
//   │      │--> Else (Right half is sorted)
//   │      │      │
//   │      │      │--> If nums[mid] < target <= nums[right]
//   │      │      │       │--> Move left = mid + 1
//   │      │      │
//   │      │      │--> Else Move right = mid - 1
//   │
//   │--> If not found, return -1
// End



// C++ program to search an element in a sorted and rotated array
#include <iostream>
#include <vector>

using namespace std;

int searchRotatedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Debugging output
        cout << "Left: " << left << ", Mid: " << mid << ", Right: " << right << ", nums[mid]: " << nums[mid] << endl;

        if (nums[mid] == target) {
            cout << "Target found at index " << mid << endl;
            return mid;
        }

        // Check if left half is sorted
        if (nums[left] <= nums[mid]) {
            cout << "Left half is sorted" << endl;
            
            // Check if target lies in the sorted left half
            if (nums[left] <= target && target < nums[mid]) {
                cout << "Target is in left half" << endl;
                right = mid - 1;
            } else {
                cout << "Target is in right half" << endl;
                left = mid + 1;
            }
        }
        // Else, right half must be sorted
        else {
            cout << "Right half is sorted" << endl;

            // Check if target lies in the sorted right half
            if (nums[mid] < target && target <= nums[right]) {
                cout << "Target is in right half" << endl;
                left = mid + 1;
            } else {
                cout << "Target is in left half" << endl;
                right = mid - 1;
            }
        }
    }

    cout << "Target not found" << endl;
    return -1;  // Target not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Searching for " << target << " in rotated sorted array..." << endl;
    int result = searchRotatedArray(nums, target);
    cout << "Final Result: " << result << endl;

    return 0;
}



// G:\dsa_c++\build\Debug>outDebug.exe
// Searching for 0 in rotated sorted array...
// Searching for 0 in rotated sorted array...
// Left: 0, Mid: 3, Right: 6, nums[mid]: 7
// Left: 0, Mid: 3, Right: 6, nums[mid]: 7
// Left half is sorted
// Target is in right half
// Left: 4, Mid: 5, Right: 6, nums[mid]: 1
// Left half is sorted
// Target is in left half
// Left: 4, Mid: 4, Right: 4, nums[mid]: 0
// Target found at index 4
// Final Result: 4
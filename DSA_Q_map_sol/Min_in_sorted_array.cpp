// Concept Explanation
// We have a sorted array that has been rotated some number of times, and our task is to find the minimum element in O(log n) time. The key observation here is that a rotated sorted array consists of two sorted subarrays—one increasing sequence followed by another increasing sequence.

// Observations:
// If the array were not rotated, the minimum element would be at index 0.
// After rotation, the array can be divided into two parts:
// Left part: Elements that were originally at the start of the sorted array but have now shifted.
// Right part: Elements that were rotated from the end of the sorted array and are now at the beginning.
// The minimum element is the "pivot point" where the rotation happens.

// Flowchart
//             Start
//               |
//          Initialize low = 0, high = n-1
//               |
//        While (low < high)
//               |
//           Find mid = (low + high) / 2
//               |
//     nums[mid] > nums[high] ?
//         /          \
//       Yes          No
//    low = mid + 1   high = mid
//         \          /
//            End Loop
//               |
//           Return nums[low]

#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum element in a rotated sorted array
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2; // Avoids overflow

        cout << "Debug: low=" << low << ", mid=" << mid << ", high=" << high << endl;

        if (nums[mid] > nums[high]) {
            // Min is in the right half
            low = mid + 1;
        } else {
            // Min is in the left half (or at mid)
            high = mid;
        }
    }

    return nums[low]; // The minimum element
}

int main() {
    int n;
    cout << "Enter the number of elements in the rotated sorted array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " unique sorted and rotated elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Finding and printing the minimum element
    int minElement = findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << minElement << endl;

    return 0;
}

// Complexity Analysis
// The time complexity for this approach is O(log n), where n is the number of elements in the array.
// The space complexity is O(1) since we are using only a constant amount of extra space.


// Input
// Enter the number of elements in the rotated sorted array: 5  
// Enter 5 unique sorted and rotated elements: 4 5 1 2 3
// Output
// Debug: low=0, mid=2, high=4
// Debug: low=3, mid=3, high=4
// The minimum element in the rotated sorted array is: 1
// In the above example, the input array is [4, 5, 1, 2, 3], which is a sorted array rotated at index 2. The minimum element in the array is 1, which is correctly identified by the algorithm.

// G:\dsa_c++\DSA_Q_map_sol>g++ -o program Min_in_sorted_array.cpp

// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter the number of elements in the rotated sorted array: 7 
// Enter 7 unique sorted and rotated elements: 4 5 6 7 0 1 2
// Debug: low=0, mid=3, high=6
// Debug: low=4, mid=5, high=6
// Debug: low=4, mid=4, high=5
// The minimum element in the rotated sorted array is: 0
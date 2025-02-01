// Flow of the code
//        Start
//           |
//    Input n, nums[]
//           |
//    Is n == 1?
//           |
//         Yes
//           |
//    Return 0 (peak at index 0)
//           |
//         No
//           |
//    Is nums[0] > nums[1]?
//           |
//         Yes
//           |
//    Return 0 (peak at first index)
//           |
//         No
//           |
//    Is nums[n-1] > nums[n-2]?
//           |
//         Yes
//           |
//    Return n-1 (peak at last index)
//           |
//         No
//           |
//      For each element i (1 to n-2):
//           |
//        Is nums[i] > nums[i-1] and nums[i] > nums[i+1]?
//           |
//         Yes
//           |
//    Return i (peak at index i)
//           |
//         No
//           |
//    Continue to next element
//           |
//        End



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Debugging output to track the flow
        cout << "Array: ";
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n\n";
        
        // Edge case for array of size 1
        if (n == 1) {
            cout << "Single element, peak at index 0\n";
            return 0;
        }

        // Checking first element
        if (nums[0] > nums[1]) {
            cout << "Peak found at index 0 (first element is greater than second)\n";
            return 0;
        }
        
        // Checking last element
        if (nums[n-1] > nums[n-2]) {
            cout << "Peak found at index " << n-1 << " (last element is greater than second last)\n";
            return n-1;
        }

        // Debugging each step for general case
        for (int i = 1; i < n - 1; i++) {
            cout << "Checking element nums[" << i << "] = " << nums[i] << "\n";
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                cout << "Peak found at index " << i << " (nums[" << i << "] > nums[" << i-1 << "] and nums[" << i << "] > nums[" << i+1 << "])\n";
                return i;
            }
        }

        return -1;  // In case no peak is found, but the problem guarantees a peak exists.
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int peakIndex = solution.findPeakElement(nums);
    cout << "\nPeak Element Index: " << peakIndex << "\n";

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// Example 1:   
// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter the number of elements in the array: 7
// Enter 7 integers: 1 2 3 4 2 7 1    
// Array: 1 2 3 4 2 7 1 

// Checking element nums[1] = 2
// Checking element nums[2] = 3
// Checking element nums[3] = 4
// Peak found at index 3 (nums[3] > nums[2] and nums[3] > nums[4])

// Peak Element Index: 3
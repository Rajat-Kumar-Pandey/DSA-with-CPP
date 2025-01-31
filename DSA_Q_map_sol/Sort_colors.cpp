// This problem is commonly known as the Dutch National Flag problem, and it can be solved efficiently using a three-pointer approach (or three-way partitioning) in a single pass (O(n) time complexity) with constant extra space (O(1)).

// Time Complexity
// O(n): Since each element is processed at most once.
// Space Complexity
// O(1): We only use a few extra variables.

// Flowchart Representation
// I'll describe the key steps so you can create a flowchart:

// Start
// Initialize three pointers low = 0, mid = 0, high = n-1
// While mid <= high, do:
// If nums[mid] == 0:
// Swap nums[low] and nums[mid]
// Increment low and mid
// Else if nums[mid] == 1:
// Increment mid
// Else if nums[mid] == 2:
// Swap nums[mid] and nums[high]
// Decrement high
// End when mid > high


#include <iostream>
#include <vector>
using namespace std;

// Function to print the array (for debugging)
void printArray(vector<int>& nums, string message) {
    cout << message << ": ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to sort colors using Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    printArray(nums, "Initial array");

    while (mid <= high) {
        cout << "low=" << low << ", mid=" << mid << ", high=" << high << " | nums[mid]=" << nums[mid] << endl;

        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
        printArray(nums, "After step");
    }
    
    printArray(nums, "Final sorted array");
}

// Driver function
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (only 0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


// Output
// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter the number of elements: 5
// Enter the elements (only 0, 1, 2): 2 2 1 1 0
// Initial array: 2 2 1 1 0 
// low=0, mid=0, high=4 | nums[mid]=2
// After step: 0 2 1 1 2
// low=0, mid=0, high=3 | nums[mid]=0
// After step: 0 2 1 1 2
// low=1, mid=1, high=3 | nums[mid]=2
// After step: 0 1 1 2 2
// low=1, mid=1, high=2 | nums[mid]=1
// After step: 0 1 1 2 2
// low=1, mid=2, high=2 | nums[mid]=1
// After step: 0 1 1 2 2 
// Final sorted array: 0 1 1 2 2
// Sorted array: 0 1 1 2 2
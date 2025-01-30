// Implementation Steps
// Place numbers in correct positions using cyclic sort.
// Find the first missing positive integer.
// Test with a hardcoded sample first.
// Allow user input to test dynamically.

// Start
//  |
//  |---> Iterate over array:
//  |      |
//  |      |---> If nums[i] is in range [1, N] and nums[i] != nums[nums[i]-1]
//  |            Swap nums[i] and nums[nums[i]-1]
//  |            Repeat step until placed correctly
//  |
//  |---> Iterate over array again:
//  |      |
//  |      |---> If nums[i] != i+1, return i+1 (first missing positive)
//  |
//  |---> If all numbers are placed correctly, return N+1
// End

#include <iostream>
#include <vector>
using namespace std;

// Function to find the smallest missing positive number
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Place numbers in correct positions
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);  // Swap the number to its correct position
        }
    }

    // Step 2: Find the first missing positive number
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all numbers from 1 to n are present, return n+1
    return n + 1;
}

// Function to print the array (for debugging)
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Driver Code
int main() {
    // Step 1: Test with a predefined sample input
    vector<int> testArray = {3, 4, -1, 1};
    cout << "Testing with predefined input: ";
    printArray(testArray);
    int result = firstMissingPositive(testArray);
    cout << "Smallest missing positive number: " << result << endl << endl;

    // Step 2: Take user input and run the function
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    vector<int> userArray(size);
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> userArray[i];
    }

    cout << "Input array: ";
    printArray(userArray);

    int missingNumber = firstMissingPositive(userArray);
    cout << "Smallest missing positive number: " << missingNumber << endl;

    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)
// where N is the number of elements in the array.
// The time complexity is O(N) because we iterate over the array twice, each time taking O(N) time.
// The space complexity is O(1) because we use a constant amount of extra space for variables.
// The cyclic sort algorithm is used to place the numbers in their correct positions, and then we find the first missing positive number by iterating over the array.
// The algorithm works by placing each number in its correct position (if it is in the range [1, N] and not already placed correctly).
// After placing the numbers, we iterate over the array again to find the first missing positive number.
// If all numbers from 1 to N are present, the missing number is N+1.

// Sample Input/Output
// G:\dsa_c++\build\Debug>outDebug.exe
// Testing with predefined input: 3 4 -1 1 
// Smallest missing positive number: 2

// Enter size of the array: 5
// Enter 5 integers: 1 2 4 -1 5 3
// Input array: 1 2 4 -1 5 
// Smallest missing positive number: 3

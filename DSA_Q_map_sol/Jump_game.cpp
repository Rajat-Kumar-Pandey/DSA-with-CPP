// Concept Explanation: Jump Game
// This problem is a greedy algorithm problem where we determine if we can reach the last index from the first index using the given jump lengths.

// Greedy Approach (Optimal Solution)
// Keep track of the farthest index you can reach (maxReach).
// Iterate through the array and check if the current index is within the maxReach.
// Update maxReach based on the maximum possible jump from the current index.
// If maxReach reaches or exceeds the last index, return true.
// If at any point, the current index exceeds maxReach, return false (you are stuck).

// Flowchart for Understanding
// Steps
// Initialize maxReach = 0
// Loop through each index i in nums:
// If i > maxReach, return false (we got stuck).
// Update maxReach = max(maxReach, i + nums[i]).
// If maxReach >= last index, return true.
// If the loop completes, return true.

// Time Complexity Analysis
// O(n) → We iterate through the array only once.
// O(1) Space Complexity → We only use a variable maxReach.


#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

// Function to check if we can reach the last index
bool canJump(vector<int>& nums) {
    int maxReach = 0; // The farthest index we can reach

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) {
            cout << "Stuck at index " << i << ". Cannot move forward!" << endl;
            return false;  // If we reach an index beyond maxReach, return false
        }

        maxReach = max(maxReach, i + nums[i]); // Update max reachable index
        cout << "At index " << i << " with jump " << nums[i] 
             << ", maxReach updated to: " << maxReach << endl;

        if (maxReach >= nums.size() - 1) {
            cout << "Can reach the last index!" << endl;
            return true;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Debugging information
    cout << "\nProcessing the given array...\n";
    
    if (canJump(nums)) {
        cout << "Output: true (You can reach the last index)\n";
    } else {
        cout << "Output: false (You cannot reach the last index)\n";
    }

    return 0;
}

// Test Case 1:
// Enter the number of elements in the array: 5
// Enter the elements of the array: 2 3 1 1 4
// Processing the given array...
// At index 0 with jump 2, maxReach updated to: 2
// At index 1 with jump 3, maxReach updated to: 4
// At index 2 with jump 1, maxReach updated to: 4
// At index 3 with jump 1, maxReach updated to: 4
// At index 4 with jump 4, maxReach updated to: 8
// Can reach the last index!
// Output: true (You can reach the last index)

// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter the number of elements in the array: 5
// Enter the elements of the array: 1 3 1 0 1

// Processing the given array...
// At index 0 with jump 1, maxReach updated to: 1
// At index 1 with jump 3, maxReach updated to: 4
// Can reach the last index!
// Output: true (You can reach the last index)
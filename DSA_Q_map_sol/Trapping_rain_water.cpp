
// Understanding the problem visually:

// Water can be trapped at a given position if there is a taller bar to both the left and right of that position.
// The amount of water trapped above a bar at position i depends on the minimum of the maximum heights to the left and right of i, minus the height of the bar at i.
// If the minimum of the left and right maximum heights is greater than the height of the current bar, the difference will give the amount of water that can be trapped above that bar.

// Approach:
// Start
// Initialize left_max and right_max arrays.
// Compute left_max array:
// Traverse from left to right: left_max[i] = max(left_max[i-1], height[i])
// Compute right_max array:
// Traverse from right to left: right_max[i] = max(right_max[i+1], height[i])
// Initialize total_water to 0.
// Traverse each index i:
// Calculate the trapped water as water = min(left_max[i], right_max[i]) - height[i]
// If water > 0, add it to total_water.
// Output total_water.



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;  // No water can be trapped if there are less than 3 bars

    // Step 1: Initialize left_max and right_max arrays
    vector<int> left_max(n, 0);
    vector<int> right_max(n, 0);

    // Step 2: Fill left_max array
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Step 3: Fill right_max array
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Debugging: Print left_max and right_max arrays
    cout << "left_max: ";
    for (int i = 0; i < n; ++i) {
        cout << left_max[i] << " ";
    }
    cout << endl;

    cout << "right_max: ";
    for (int i = 0; i < n; ++i) {
        cout << right_max[i] << " ";
    }
    cout << endl;

    // Step 4: Calculate total trapped water
    int total_water = 0;
    for (int i = 0; i < n; ++i) {
        int water = min(left_max[i], right_max[i]) - height[i];
        if (water > 0) {
            total_water += water;
        }

        // Debugging: Print trapped water at each index
        cout << "At index " << i << ": height = " << height[i] << ", trapped water = " << water << endl;
    }

    return total_water;
}

int main() {
    // Demo test cases
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2 = {4,2,0,3,2,5};

    cout << "Demo Test 1: Water Trapped = " << trap(height1) << endl;
    cout << "Demo Test 2: Water Trapped = " << trap(height2) << endl;

    // User input section
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> user_height(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; ++i) {
        cin >> user_height[i];
    }

    cout << "Water trapped for user input: " << trap(user_height) << endl;

    return 0;
}


// Output
// G:\dsa_c++\build\Debug>outDebug.exe
// Demo Test 1: Water Trapped = left_max: 0 1 1 2 2 2 2 3 3 3 3 3 
// right_max: 3 3 3 3 3 3 3 3 2 2 2 1       
// At index 0: height = 0, trapped water = 0
// At index 1: height = 1, trapped water = 0
// At index 2: height = 0, trapped water = 1
// At index 3: height = 2, trapped water = 0
// At index 4: height = 1, trapped water = 1
// At index 5: height = 0, trapped water = 2
// At index 6: height = 1, trapped water = 1
// At index 7: height = 3, trapped water = 0
// At index 8: height = 2, trapped water = 0
// At index 9: height = 1, trapped water = 1
// At index 10: height = 2, trapped water = 0
// At index 11: height = 1, trapped water = 0
// 6
// Demo Test 2: Water Trapped = left_max: 4 4 4 4 4 5
// right_max: 5 5 5 5 5 5
// At index 0: height = 4, trapped water = 0
// At index 1: height = 2, trapped water = 2
// At index 2: height = 0, trapped water = 4
// At index 3: height = 3, trapped water = 1
// At index 4: height = 2, trapped water = 2
// At index 5: height = 5, trapped water = 0
// 9
// Enter the number of bars: 5
// Enter the heights of the bars: 2 3 4 4 2 
// Water trapped for user input: left_max: 2 3 4 4 4 
// right_max: 4 4 4 4 2
// At index 0: height = 2, trapped water = 0
// At index 1: height = 3, trapped water = 0
// At index 2: height = 4, trapped water = 0
// At index 3: height = 4, trapped water = 0
// At index 4: height = 2, trapped water = 0
// 0
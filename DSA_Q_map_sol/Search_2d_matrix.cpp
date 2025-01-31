// Concept Explanation
// The given matrix has two important properties:

// Each row is sorted in non-decreasing order → This means we can use binary search within each row.
// The first integer of each row is greater than the last integer of the previous row → This means that the matrix behaves like a flattened 1D sorted array when read row-wise.
// Because of these properties, we can treat the matrix as a sorted 1D array and apply binary search to achieve an O(log(m * n)) time complexity.


// Flowchart Explanation
// Initialize low = 0 and high = m * n - 1 (total elements in matrix).
// While low <= high:
// Compute mid = (low + high) / 2.
// Convert mid to matrix indices (row = mid / n, col = mid % n).
// If matrix[row][col] == target, return true.
// If matrix[row][col] < target, move to right half (low = mid + 1).
// Else, move to left half (high = mid - 1).
// If no match is found, return false. 



#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search on the matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns
    
    int low = 0, high = m * n - 1;

    // Binary Search in 1D mapped matrix
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        int row = mid / n;  // Finding row index
        int col = mid % n;  // Finding column index
        
        cout << "Checking matrix[" << row << "][" << col << "] = " << matrix[row][col] << endl;
        
        if (matrix[row][col] == target) {
            cout << "Target found at (" << row << ", " << col << ")" << endl;
            return true;
        }
        else if (matrix[row][col] < target)
            low = mid + 1;  // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    cout << "Target not found!" << endl;
    return false; // Target not found
}

int main() {
    int m, n, target;

    // Taking user input for matrix dimensions
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Taking user input for matrix elements
    cout << "Enter elements row-wise in sorted order:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Taking user input for target
    cout << "Enter the target number: ";
    cin >> target;

    // Calling the function and displaying result
    bool found = searchMatrix(matrix, target);
    if (found)
        cout << "Result: true (Target exists in matrix)" << endl;
    else
        cout << "Result: false (Target not found in matrix)" << endl;

    return 0;
}

// Time Complexity: O(log(m * n))
// Space Complexity: O(1)

// Test Case 1:
// Enter number of rows: 3
// Enter number of columns: 4
// Enter elements row-wise in sorted order:
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60
// Enter the target number: 3
// Checking matrix[1][0] = 10
// Checking matrix[0][2] = 5
// Checking matrix[0][1] = 3
// Target found at (0, 1)
// Result: true (Target exists in matrix)


// Test Case 2:
// G:\dsa_c++\DSA_Q_map_sol>g++ -o program Search_2d_matrix.cpp

// G:\dsa_c++\DSA_Q_map_sol>program.exe
// Enter number of rows: 5
// Enter number of columns: 5
// Enter elements row-wise in sorted order:
// 1 3 5 7 9 12 14 16 17 19 21 24 25 27 29 31 34 35 36 38 41 44 46 48 50
// Enter the target number: 29
// Checking matrix[2][2] = 25
// Checking matrix[3][3] = 36
// Checking matrix[3][0] = 31
// Checking matrix[2][3] = 27
// Checking matrix[2][4] = 29
// Target found at (2, 4)
// Result: true (Target exists in matrix)
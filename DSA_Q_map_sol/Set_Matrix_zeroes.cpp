// You are given an m x n integer matrix. If any element in the matrix is 0, then you need to set its entire row and column to 0. This operation must be performed in place, meaning you should not use extra space other than a few variables.

// Flowchart
//     Start
//       ↓
//     Identify all positions where matrix[i][j] == 0
//       ↓
//     Mark rows and columns for zeroing
//       ↓
//     Update the matrix accordingly
//       ↓
//     End


// Step-by-step transformation:

// Identify 0s at positions matrix[0][0] and matrix[0][3].
// Set entire row 0 to 0: [0, 0, 0, 0].
// Set entire column 0 to 0: matrix[1][0] = matrix[2][0] = 0.
// Set entire column 3 to 0: matrix[1][3] = matrix[2][3] = 0.

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Step 1: Check if the first row and first column need to be zero
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Step 2: Use first row and first column as markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the first column
                matrix[0][j] = 0; // Mark the first row
            }
        }
    }

    cout << "Matrix after marking:\n";
    printMatrix(matrix);

    // Step 3: Zero out cells based on markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    cout << "Matrix after applying zeroes:\n";
    printMatrix(matrix);

    // Step 4: Zero out the first row and first column if needed
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    cout << "Final Matrix:\n";
    printMatrix(matrix);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    setZeroes(matrix);

    return 0;
}


// Output
// Original Matrix: 
// 1 1 1
// 1 0 1
// 1 1 1
// -------------------
// Matrix after marking:
// 1 0 1
// 0 0 1
// 1 1 1
// -------------------
// Matrix after applying zeroes:
// 1 0 1
// 0 0 0
// 1 0 1
// -------------------
// Final Matrix:
// 1 0 1
// 0 0 0
// 1 0 1

// Time Complexity: O(m * n)
// Space Complexity: O(1)

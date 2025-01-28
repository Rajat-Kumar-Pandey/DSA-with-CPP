// Concept Explanation
// The matrix is traversed layer by layer

// Traverse the top row from left to right.
// Traverse the rightmost column from top to bottom.
// Traverse the bottom row from right to left (if still valid).
// Traverse the leftmost column from bottom to top (if still valid).

// After completing one layer, we move to the next inner layer and repeat until all elements are visited.

// Algorithm
// Define the boundaries of the matrix:

// top: Initially 0 (top row index)
// bottom: Initially m-1 (bottom row index)
// left: Initially 0 (left column index)
// right: Initially n-1 (right column index)
// Use a while loop (while top <= bottom and left <= right) to iterate through the layers:

// Top Row: Traverse from left to right, then increment top.
// Right Column: Traverse from top to bottom, then decrement right.
// Bottom Row: If top <= bottom, traverse from right to left, then decrement bottom.
// Left Column: If left <= right, traverse from bottom to top, then increment left.
// Add elements to the result list in the order of traversal.

// Return the result list.

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse the top row from left to right
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Traverse the right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse the bottom row from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse the left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);
    cout << "Spiral order of the matrix: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// Approach:
// Simultaneous Update Problem: Since we must update all cells at the same time, we need a way to store the new state without affecting the original state before all updates are complete.
// In-Place Update Solution: Instead of using extra space, we encode the transition states:
// 0 → 1 (Dead → Live) can be represented as 2
// 1 → 0 (Live → Dead) can be represented as -1
// This allows us to store both old and new states in the same grid.
// Processing Rules: Iterate through the board and count live neighbors using the 8-directional traversal.
// Decoding Final States: Convert 2 → 1 and -1 → 0 after processing.

//     directions that stores the relative positions of each of the 8 neighbors:
//     int directions[8][2] = {
//     {-1, -1}, {-1, 0}, {-1, 1},  // Top-left, Top, Top-right
//     {0, -1},         {0, 1},      // Left,       Right
//     {1, -1}, {1, 0}, {1, 1}       // Bottom-left, Bottom, Bottom-right
//     };
//    self element is assumed to be at (0,0) and its neighbors are at (-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)

//     FOR i FROM 0 TO m-1:
//         FOR j FROM 0 TO n-1:
//             live_neighbors = 0

//             FOR each (dx, dy) in DIRECTIONS:
//                 ni, nj = i + dx, j + dy
//                 IF ni, nj are within bounds:
//                     IF board[ni][nj] is 1 or -1:
//                         live_neighbors += 1

//             IF board[i][j] is 1:
//                 IF live_neighbors < 2 OR live_neighbors > 3:
//                     board[i][j] = -1
//             ELSE:
//                 IF live_neighbors == 3:
//                     board[i][j] = 2

//     FOR i FROM 0 TO m-1:
//         FOR j FROM 0 TO n-1:
//             IF board[i][j] == -1:
//                 board[i][j] = 0
//             ELSE IF board[i][j] == 2:
//                 board[i][j] = 1
#include <iostream>
#include <vector>
using namespace std;

// Function to print the board (for debugging)
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Game of Life function with debugging steps
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> direction = {
        {-1, -1}, {-1, 0}, {-1, 1},  // Top-left, Top, Top-right
        {0, -1},         {0, 1},      // Left,       Right
        {1, -1}, {1, 0}, {1, 1}       // Bottom-left, Bottom, Bottom-right
    };

    cout << "Initial board state:\n";
    printBoard(board);

    // Step 1: Modify board in-place using encoding
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;

            // Count live neighbors
            for (const auto& dir : direction) {
                int ni = i + dir[0];
                int mj = j + dir[1];

                if (ni >= 0 && ni < m && mj >= 0 && mj < n && abs(board[ni][mj]) == 1) {
                    live++;
                }
            }

            cout << "Cell (" << i << ", " << j << ") has " << live << " live neighbors.\n";

            // Apply rules:
            if (board[i][j] == 1 && (live < 2 || live > 3)) {
                cout << "Cell (" << i << ", " << j << ") dies (1 -> 0, marked as -1).\n";
                board[i][j] = -1; // Mark as "was 1, now 0"
            }
            if (board[i][j] == 0 && live == 3) {
                cout << "Cell (" << i << ", " << j << ") becomes alive (0 -> 1, marked as 2).\n";
                board[i][j] = 2;  // Mark as "was 0, now 1"
            }
        }
    }

    cout << "\nBoard after encoding changes:\n";
    printBoard(board);

    // Step 2: Decode new states
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1) {
                cout << "Cell (" << i << ", " << j << ") final state: 0\n";
                board[i][j] = 0;  // Convert back to 0
            }
            if (board[i][j] == 2) {
                cout << "Cell (" << i << ", " << j << ") final state: 1\n";
                board[i][j] = 1;   // Convert back to 1
            }
        }
    }

    cout << "\nFinal board state:\n";
    printBoard(board);
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> board(m, vector<int>(n));
    cout << "Enter the elements of the board (0 or 1): " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    gameOfLife(board);

    return 0;
}



// Time complexity: O(m*n), where m is the number of rows and n is the number of columns in the board.
// Space complexity: O(1) since we are updating the board in-place without using any extra space.
// output:
// G:\dsa_c++\build\Debug>outDebug.exe
// Enter the number of rows: 3
// Enter the number of columns: 3
// Enter the elements of the board (0 or 1): 
// 1 0 0 1 1 0 1 1 0
// Initial board state:
// 1 0 0
// 1 1 0
// 1 1 0

// Cell (0, 0) has 2 live neighbors.
// Cell (0, 1) has 3 live neighbors.
// Cell (0, 1) becomes alive (0 -> 1, marked as 2).
// Cell (0, 2) has 1 live neighbors.
// Cell (1, 0) has 4 live neighbors.
// Cell (1, 0) dies (1 -> 0, marked as -1).
// Cell (1, 1) has 4 live neighbors.
// Cell (1, 1) dies (1 -> 0, marked as -1).
// Cell (1, 2) has 2 live neighbors.
// Cell (2, 0) has 3 live neighbors.
// Cell (2, 1) has 3 live neighbors.
// Cell (2, 2) has 2 live neighbors.

// Board after encoding changes:
// 1 2 0
// -1 -1 0
// 1 1 0

// Cell (0, 1) final state: 1
// Cell (1, 0) final state: 0
// Cell (1, 1) final state: 0

// Final board state:
// 1 1 0
// 0 0 0
// 1 1 0

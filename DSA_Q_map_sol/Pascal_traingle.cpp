#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;

    if (numRows == 0) return triangle;

    triangle.push_back({1});

    for (int i = 1; i < numRows; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);
    cout << "Pascal's Triangle:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
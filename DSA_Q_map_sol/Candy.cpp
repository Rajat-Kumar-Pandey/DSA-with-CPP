// Understanding the Problem
// We need to distribute candies to children based on their ratings, while satisfying the following conditions:

// Each child gets at least one candy.
// Children with higher ratings must receive more candies than their immediate neighbors.
// Our goal is to minimize the total number of candies distributed.
// Flow of code
//         +--------------------+
//         |  Start            |
//         +--------------------+
//                  |
//                  v
//         +--------------------+
//         |  Initialize candies |
//         |  with all 1s        |
//         +--------------------+
//                  |
//                  v
//         +----------------------------+
//         |  Left to Right Pass         |
//         |  if ratings[i] > ratings[i-1]|
//         |  candies[i] = candies[i-1] +1|
//         +----------------------------+
//                  |
//                  v
//         +----------------------------+
//         |  Right to Left Pass         |
//         |  if ratings[i] > ratings[i+1]|
//         |  candies[i] = max(candies[i], |
//         |             candies[i+1] +1)  |
//         +----------------------------+
//                  |
//                  v
//         +----------------------+
//         |  Sum all candies     |
//         |  Return the result   |
//         +----------------------+
//                  |
//                  v
//         +--------------------+
//         |  End              |
//         +--------------------+

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    // Left to Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left pass
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Sum up candies
    int totalCandies = 0;
    for (int c : candies) {
        totalCandies += c;
    }

    return totalCandies;
}

// Main function for testing
int main() {
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies needed: " << candy(ratings) << endl; // Output: 5

    ratings = {1, 2, 2};
    cout << "Minimum candies needed: " << candy(ratings) << endl; // Output: 4

    return 0;
}


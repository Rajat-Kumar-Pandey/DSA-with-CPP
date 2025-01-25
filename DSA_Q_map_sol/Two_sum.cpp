#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // To store the number and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return {}; // In case there is no solution, though the problem guarantees one
}

int main() {
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices of the two numbers are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
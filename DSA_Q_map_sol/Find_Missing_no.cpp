#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;

    // Mark each number's corresponding index as negative
    for (int i = 0; i < n; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    // Collect all indices that have positive values
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = findDisappearedNumbers(nums);
    cout << "Missing numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
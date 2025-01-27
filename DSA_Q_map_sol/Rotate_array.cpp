#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // In case k is greater than the size of the array

    // Reverse the entire array
    reverse(nums.begin(), nums.end());
    // Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of steps to rotate: ";
    cin >> k;

    rotate(nums, k);

    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
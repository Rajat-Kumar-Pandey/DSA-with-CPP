#include <iostream>
#include <vector>
using namespace std;
// Boyer-Moore Voting Algorithm
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
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

    int result = majorityElement(nums);
    cout << "The majority element is: " << result << endl;

    return 0;
}
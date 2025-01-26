#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // Floyd's Tortoise and Hare (Cycle Detection)
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Finding the intersection point of the two runners
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Finding the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int n;
    cout << "Enter the number of elements (n + 1): ";
    cin >> n;

    vector<int> nums(n + 1);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n + 1; i++) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
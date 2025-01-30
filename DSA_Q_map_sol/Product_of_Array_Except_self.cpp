#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);

    // Calculate left products
    int leftProduct = 1;
    cout << "Calculating left products:" << endl;
    for (int i = 0; i < n; i++) {
        answer[i] = leftProduct;
        cout << "Left Product at index " << i << ": " << answer[i] << endl; // Debug print for left products
        leftProduct *= nums[i];
    }

    // Calculate right products and multiply with left products
    int rightProduct = 1;
    cout << "Calculating right products and updating answer array:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= rightProduct;
        cout << "Answer at index " << i << ": " << answer[i] << " (after multiplying by rightProduct " << rightProduct << ")" << endl; // Debug print for updated answer
        rightProduct *= nums[i];
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Debugging pause
    // Debugging pause (wait for user to press Enter before closing)
    cout << "Press Enter to exit..." << endl;
    cin.ignore();  // Ignore any leftover newline characters
    cin.get();  // Wait for user input before closing the program
    return 0;
}

// QuickSelect (Optimal: Average O(n), Worst O(n²))
// This is a variation of QuickSort's partitioning:

// Pick a random pivot.
// Partition the array into two halves (greater and smaller than pivot).
// Recursively apply the partitioning on the side containing the kth largest element.
// Stops early when we find the kth largest element.
// Average Time Complexity: O(n) (Partition reduces problem size by half each time).

// Worst-case Time Complexity: O(n²) (If bad pivot is always chosen, rare case).

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Partition function (rearranges array around pivot)
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];  // Choosing the last element as pivot
    int i = left; // This will be the correct position for the pivot

    cout << "\n[DEBUG] Partitioning with pivot: " << pivot << endl;
    cout << "[DEBUG] Before Partition: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) {  // Sorting in descending order
            swap(nums[i], nums[j]);  // Move larger elements to the left
            i++;
        }
    }
    swap(nums[i], nums[right]);  // Place pivot at its correct position

    cout << "[DEBUG] After Partition: ";
    for (int num : nums) cout << num << " ";
    cout << "\n[DEBUG] Pivot Final Position: " << i << "\n\n";

    return i;  // Return final index of pivot
}

// QuickSelect function to find the kth largest element
int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left]; // Base case: only one element

    int pivotIndex = partition(nums, left, right); // Partition and get pivot index

    cout << "[DEBUG] Searching for k = " << k << ", Pivot Index = " << pivotIndex << endl;

    if (pivotIndex == k) {
        cout << "[DEBUG] Found the kth largest element: " << nums[k] << endl;
        return nums[k];  // Found the kth largest element
    } else if (pivotIndex < k) {
        cout << "[DEBUG] Searching in the right half...\n";
        return quickSelect(nums, pivotIndex + 1, right, k); // Search right half
    } else {
        cout << "[DEBUG] Searching in the left half...\n";
        return quickSelect(nums, left, pivotIndex - 1, k); // Search left half
    }
}

// Wrapper function to call QuickSelect
int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1); // k-1 for 0-based index



    // this is the code for the same problem using priority queue
    //     priority_queue<int,vector<int>,greater<int>> minheap;

    // for(int num :nums){
    //     minheap.push(num);
    //     if(minheap.size() > k ){
    //         minheap.pop();
    //     }
    // }
    // return minheap.top();   --> this will return the kth largest element.
    // this code is more efficient than the above code.
    // the time complexity of this code is O(nlogk) and the space complexity is O(k)
}

// Main function with user input
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid input! k must be between 1 and " << n << ".\n";
        return 1;
    }

    cout << "\nFinding the " << k << "th largest element...\n";
    int result = findKthLargest(nums, k);

    cout << "\nThe " << k << "th largest element is: " << result << endl;
    return 0;
}

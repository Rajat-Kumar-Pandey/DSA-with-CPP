#include <iostream>
using namespace std;

int* createArray(int n) {
    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int* arr = createArray(n);
    cout << "Max: " << findMax(arr, n) << endl;
    cout << "Min: " << findMin(arr, n) << endl;

    delete[] arr; // Free the allocated memory
    return 0;
}
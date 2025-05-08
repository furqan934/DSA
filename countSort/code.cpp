#include<iostream>
using namespace std;
void countSort(int arr[], int n, int k) {
    int count[k + 1] = {0};
    int output[n];

    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update count array to store cumulative counts
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void traversing(int arr[],int n){
    for (int i =0 ; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8; // Maximum value in the array

    cout << "Original array: ";
    traversing(arr,n);

    countSort(arr, n, k);

    cout << "Sorted array: ";
    traversing(arr,n);

    return 0;
}
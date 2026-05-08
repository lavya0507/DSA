#include <stdio.h>

long long mergeAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left, right, and across the split
        inv_count += mergeAndCount(arr, temp, left, mid);
        inv_count += mergeAndCount(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left;    // Index for result
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j], so an inversion exists
            // All elements from arr[i] to arr[mid] are > arr[j]
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    printf("Number of inversions: %lld\n", mergeAndCount(arr, temp, 0, n - 1));
    return 0;
}

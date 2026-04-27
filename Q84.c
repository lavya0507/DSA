#include <stdio.h>

/**
 * Function to perform insertion sort on an integer array.
 * It conceptually splits the array into sorted and unsorted parts.
 * [GeeksforGeeks](https://geeksforgeeks.org)
 */
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // Pick the next element to be inserted
        j = i - 1;

        /* Shift elements of arr[0..i-1] that are greater than key 
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
}

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read n space-separated integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    insertionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}

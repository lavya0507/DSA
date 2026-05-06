#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    if (n <= 1) return;

    // 1. Find the maximum element to define the range
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 3. Compute prefix sums to find actual positions
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build output array
    int *output = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting stall positions
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' between them
int isPossible(int stalls[], int n, int k, int dist) {
    int count = 1; // Place first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= dist) {
            count++;
            last_position = stalls[i];
            if (count >= k) return 1; // Successfully placed all cows
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *stalls = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stalls
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search on the answer
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, n, k, mid)) {
            result = mid;     // This distance is viable, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1;    // Too far apart, reduce the distance
        }
    }

    printf("%d\n", result);

    free(stalls);
    return 0;
}

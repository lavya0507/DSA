#include <stdio.h>
#include <stdbool.h>

// Check if all boards can be painted in 'limit' time with 'k' painters
bool isPossible(int boards[], int n, int k, long long limit) {
    int paintersCount = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than the limit, it's impossible
        if (boards[i] > limit) return false;

        if (currentSum + boards[i] <= limit) {
            currentSum += boards[i];
        } else {
            // Assign to a new painter
            paintersCount++;
            currentSum = boards[i];
            
            if (paintersCount > k) return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) low = boards[i]; // Largest single board
        high += boards[i];                    // Sum of all boards
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;       // This limit works, try smaller
            high = mid - 1;
        } else {
            low = mid + 1;      // Limit too small, increase it
        }
    }

    printf("%lld\n", result);

    return 0;
}

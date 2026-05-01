#include <stdio.h>
#include <stdbool.h>
#include <numeric>

// Function to check if a specific 'pageLimit' allows allocation
bool isPossible(int arr[], int n, int m, long long pageLimit) {
    int studentsRequired = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than limit
        if (arr[i] > pageLimit) return false;

        if (currentSum + arr[i] > pageLimit) {
            // Allocate to next student
            studentsRequired++;
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }
    }
    // Check if total students used is within limit
    return studentsRequired <= m;
}

long long findPages(int arr[], int n, int m) {
    if (m > n) return -1; // More students than books

    long long sum = 0;
    int maxPage = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxPage) maxPage = arr[i];
    }

    long long start = maxPage, end = sum;
    long long result = -1;

    // Binary search to find the minimum maximum pages
    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1; // Try to reduce the max pages
        } else {
            start = mid + 1; // Increase allowed max pages
        }
    }
    return result;
}

int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};
    printf("%lld\n", findPages(arr, n, m));
    return 0;
}

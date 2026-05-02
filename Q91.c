#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Check if it's possible to paint all boards within 'limit' time
bool isPossible(const vector<int>& boards, int n, int k, long long limit) {
    int paintersCount = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= limit) {
            currentSum += boards[i];
        } else {
            // Need a new painter
            paintersCount++;
            currentSum = boards[i];
            
            // If painters exceed k, this limit is too small
            if (paintersCount > k) return false;
        }
    }
    return true;
}

long long solve() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> boards(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> boards[i];
        if (boards[i] > low) low = boards[i]; // Max element
        high += boards[i];                    // Sum of all elements
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;   // Try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;  // Need more time
        }
    }
    return result;
}

int main() {
    cout << solve() << endl;
    return 0;
}

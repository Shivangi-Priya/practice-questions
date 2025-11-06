#include <iostream>

using namespace std;

// Mock API function (Assume this is provided)
bool isBadVersion(int version) {
    // Let the first bad version be 4
    return version >= 4; 
}

// --- Optimized Solution (Binary Search) ---
int firstBadVersionOptimized(int n) {
    int low = 1;
    int high = n;
    int firstBad = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            firstBad = mid;
            high = mid - 1; // Check if an earlier version is also bad
        } else {
            low = mid + 1; // The bad version must be after mid
        }
    }
    return firstBad;
}

// --- Brute-Force Solution (Linear Search) ---
int firstBadVersionBruteForce(int n) {
    for (int i = 1; i <= n; ++i) {
        if (isBadVersion(i)) {
            return i;
        }
    }
    return n;
}

int main() {
    int n = 5;
    cout << "First Bad Version (Optimized): " << firstBadVersionOptimized(n) << endl; // Output: 4
    return 0;
}
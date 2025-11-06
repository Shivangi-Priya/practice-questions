#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Binary Search) ---
int lowerBound(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1; // Look for a tighter bound on the left
        } else {
            low = mid + 1; // Target is in the right half
        }
    }
    return ans;
}

// --- Brute-Force Solution (Linear Search) ---
int lowerBoundBruteForce(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= target) {
            return i;
        }
    }
    return arr.size();
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 8};
    int target = 4;
    cout << "Lower Bound Index for " << target << ": " << lowerBound(arr, target) << endl; // Output: 2
    return 0;
}

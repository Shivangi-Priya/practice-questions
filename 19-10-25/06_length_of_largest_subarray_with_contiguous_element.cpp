#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

// --- Optimized Solution (Sliding Window / Fixed Start, Expanding End) ---
int findLengthOfLargestContiguous(const vector<int>& arr) {
    int n = arr.size();
    int maxLength = 1;

    // Fix the start of the subarray
    for (int i = 0; i < n - 1; ++i) {
        int minVal = arr[i];
        int maxVal = arr[i];
        unordered_set<int> seen;
        seen.insert(arr[i]);

        // Expand the subarray to the right
        for (int j = i + 1; j < n; ++j) {
            // Check for duplicates
            if (seen.count(arr[j])) break;
            seen.insert(arr[j]);

            minVal = min(minVal, arr[j]);
            maxVal = max(maxVal, arr[j]);

            // Check if the subarray has contiguous elements: max - min == length - 1
            if (maxVal - minVal == j - i) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// --- Brute-Force Solution (N^3 or N^2 log N) ---
// A simpler but slower check for contiguous property for every subarray (i, j)
bool isContiguous(vector<int> sub) {
    if (sub.size() <= 1) return true;
    sort(sub.begin(), sub.end());
    for (size_t k = 1; k < sub.size(); ++k) {
        if (sub[k] != sub[k - 1] + 1) return false;
    }
    return true;
}

int findLengthBruteForce(const vector<int>& arr) {
    int n = arr.size();
    int maxLength = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> sub;
            for(int k = i; k <= j; ++k) sub.push_back(arr[k]);

            if (isContiguous(sub)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength; // Complexity O(N^3 log N) or O(N^2 log N)
}

int main() {
    vector<int> arr = {10, 12, 11, 10, 13, 14};
    cout << "Largest Contiguous Subarray Length (Optimized): " << findLengthOfLargestContiguous(arr) << endl; // Output: 4
    return 0;
}
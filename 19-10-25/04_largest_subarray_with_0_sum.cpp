#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Hash Map) ---
int maxLen(const vector<int>& arr) {
    unordered_map<int, int> sumMap;
    int sum = 0;
    int maxLength = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (sum == 0) {
            maxLength = i + 1;
        } else if (sumMap.count(sum)) {
            // Found a previous sum equal to the current sum. 
            // Subarray from sumMap[sum] + 1 to i has zero sum.
            maxLength = max(maxLength, (int)i - sumMap[sum]);
        } else {
            // Store the first occurrence of this sum
            sumMap[sum] = i;
        }
    }
    return maxLength;
}

// --- Brute-Force Solution (Nested Loops) ---
int maxLenBruteForce(const vector<int>& arr) {
    int n = arr.size();
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += arr[j];
            if (currentSum == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Largest Subarray Length (Optimized): " << maxLen(arr) << endl; // Output: 5
    return 0;
}
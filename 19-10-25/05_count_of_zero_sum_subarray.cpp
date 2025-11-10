#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Hash Map) ---
long long countZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, int> sumMap;
    sumMap[0] = 1; // Base case: prefix sum of 0 exists once (before index -1)
    long long count = 0;
    int sum = 0;

    for (int num : arr) {
        sum += num;
        
        if (sumMap.count(sum)) {
            // Every time a prefix sum repeats, it means there are that many zero-sum subarrays ending here
            count += sumMap[sum];
        }
        
        sumMap[sum]++;
    }
    return count;
}

// --- Brute-Force Solution (Nested Loops) ---
long long countZeroSumSubarraysBruteForce(const vector<int>& arr) {
    int n = arr.size();
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        int currentSum = 0;
        for (int j = i; j < n; ++j) {
            currentSum += arr[j];
            if (currentSum == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    cout << "Count of Zero Sum Subarrays (Optimized): " << countZeroSumSubarrays(arr) << endl; // Output: 8
    return 0;
}
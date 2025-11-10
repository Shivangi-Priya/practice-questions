#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

// --- Optimized Solution (Summation Formula - Gauss's Formula) ---
int missingNumberOptimized(const vector<int>& nums) {
    int n = nums.size();
    // Sum of numbers from 0 to n: n * (n + 1) / 2
    int expectedSum = n * (n + 1) / 2;
    
    // Actual sum of elements in the array
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

// --- Brute-Force/Alternative Solution (Hash Set) ---
int missingNumberBruteForce(const vector<int>& nums) {
    unordered_set<int> numSet;
    for (int num : nums) {
        numSet.insert(num);
    }
    
    int n = nums.size();
    for (int i = 0; i <= n; ++i) {
        if (numSet.find(i) == numSet.end()) {
            return i;
        }
    }
    return -1; // Should not happen
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number (Optimized): " << missingNumberOptimized(nums) << endl; // Output: 2
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// --- Optimized Solution (Single Pass Hash Map) ---
vector<int> twoSumOptimized(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

// --- Brute-Force Solution (Nested Loops) ---
vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumOptimized(nums, target);
    cout << "Two Sum Indices: " << result[0] << ", " << result[1] << endl; // Output: 0, 1
    return 0;
}
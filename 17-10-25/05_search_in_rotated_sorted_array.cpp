#include <iostream>
#include <vector>

using namespace std;

// --- Optimized Solution (Binary Search) ---
int searchRotatedOptimized(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // Target is in the sorted left half
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        // Right half must be sorted
        else {
            // Target is in the sorted right half
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// --- Brute-Force Solution (Linear Search) ---
int searchRotatedBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Target Index (Optimized): " << searchRotatedOptimized(nums, target) << endl; // Output: 4
    return 0;
}
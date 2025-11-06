#include <iostream>
#include <vector>

using namespace std;


bool searchRotatedWithDuplicates(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;

        // Handle the duplicate case
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

// --- Brute-Force Solution (Linear Search) ---
bool searchRotatedBruteForce(const vector<int>& nums, int target) {
    for (int x : nums) {
        if (x == target) return true;
    }
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << "Target found (Optimized): " << searchRotatedWithDuplicates(nums, target) << endl; // Output: 1 (true)
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Dutch National Flag Algorithm) ---
void sortColorsOptimized(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Do not increment mid, as the swapped element at mid needs to be checked
        }
    }
}

// --- Brute-Force Solution (Counting Sort) ---
void sortColorsBruteForce(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int x : nums) {
        if (x == 0) count0++;
        else if (x == 1) count1++;
        else count2++;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (i < count0) nums[i] = 0;
        else if (i < count0 + count1) nums[i] = 1;
        else nums[i] = 2;
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColorsOptimized(nums);
    cout << "Sorted Array: ";
    for (int x : nums) cout << x << " "; // Output: 0 0 1 1 2 2
    cout << endl;
    return 0;
}
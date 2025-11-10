#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Hash Set) ---
vector<int> intersectionOptimized(const vector<int>& nums1, const vector<int>& nums2) {
    // Use a set for the smaller array to minimize space and lookup time
    unordered_set<int> set1(nums1.begin(), nums1.end());
    vector<int> result;

    for (int num : nums2) {
        if (set1.count(num)) {
            result.push_back(num);
            set1.erase(num); // Remove to ensure unique intersection elements
        }
    }
    return result;
}

// --- Brute-Force/Alternative Solution (Sorting and Two Pointers) ---
vector<int> intersectionBruteForce(vector<int> nums1, vector<int> nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // Found intersection element
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersectionOptimized(nums1, nums2);
    
    cout << "Intersection (Optimized): ";
    for (int x : result) cout << x << " "; // Output: 2
    cout << endl;
    return 0;
}

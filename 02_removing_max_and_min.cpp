#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();

    
    int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
    int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

  
    if (minIdx > maxIdx) swap(minIdx, maxIdx);

    int front = maxIdx + 1;

    int back = n - minIdx;

    int both = (minIdx + 1) + (n - maxIdx);

    return min({front, back, both});
}

int main() {
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << minimumDeletions(nums) << endl; // Output: 5

    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    cout << minimumDeletions(nums2) << endl; // Output: 3

    vector<int> nums3 = {101};
    cout << minimumDeletions(nums3) << endl; // Output: 1

    return 0;
}

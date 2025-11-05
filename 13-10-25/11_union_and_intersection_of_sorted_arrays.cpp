#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (int num : nums2) {
        if (s1.count(num)) {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = intersection(nums1, nums2);

    for (int x : ans) cout << x << " ";
    return 0;
}

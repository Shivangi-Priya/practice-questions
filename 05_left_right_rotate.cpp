#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; 
        reverse(nums.begin(), nums.end());

       
        reverse(nums.begin(), nums.begin() + k);

       
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution obj;
    
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    obj.rotate(nums1, k1);
    for (int x : nums1) cout << x << " ";  
    cout << endl;

    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    obj.rotate(nums2, k2);
    for (int x : nums2) cout << x << " ";
    cout << endl;

    return 0;
}

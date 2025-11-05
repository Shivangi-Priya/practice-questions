#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == total - leftSum - nums[i]) return i;
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    cout << pivotIndex(nums);
    return 0;
}

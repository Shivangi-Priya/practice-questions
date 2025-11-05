#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> result(nums.size());
    result[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result[i] = result[i - 1] + nums[i];
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = runningSum(nums);
    
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

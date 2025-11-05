#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        
        
        for (int n : nums) {
            freq[n]++;
            maxFreq = max(maxFreq, freq[n]); 
        }
        
      
        int total = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq)
                total += p.second;
        }
        
        return total;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums1 = {1, 2, 2, 3, 1, 4};
    cout << obj.maxFrequencyElements(nums1) << endl; 
    
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << obj.maxFrequencyElements(nums2) << endl; 
    
    return 0;
}

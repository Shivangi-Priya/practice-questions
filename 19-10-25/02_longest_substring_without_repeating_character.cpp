#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Sliding Window with Hash Map) ---
int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> charIndexMap;
    int n = s.length();
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < n; ++right) {
        char current_char = s[right];
        
        // If the character is found in the current window and its index is >= left boundary
        if (charIndexMap.count(current_char) && charIndexMap[current_char] >= left) {
            // Move the left boundary past the last occurrence of the repeating character
            left = charIndexMap[current_char] + 1;
        }
        
        // Update the character's last seen index
        charIndexMap[current_char] = right;
        
        // Update max length
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

// --- Brute-Force Solution (Nested Loops) ---
bool allUnique(const string& s, int start, int end) {
    unordered_map<char, bool> seen;
    for (int i = start; i <= end; ++i) {
        if (seen.count(s[i])) return false;
        seen[s[i]] = true;
    }
    return true;
}

int lengthOfLongestSubstringBruteForce(const string& s) {
    int n = s.length();
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (allUnique(s, i, j)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Length (Optimized): " << lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}
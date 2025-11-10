#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// --- Optimized Solution (Frequency Array) ---
bool isAnagramOptimized(string s, string t) {
    if (s.length() != t.length()) return false;
    
    // Use an array for O(1) access, assuming lowercase English letters (size 26)
    vector<int> counts(26, 0);

    for (char c : s) {
        counts[c - 'a']++;
    }
    for (char c : t) {
        counts[c - 'a']--;
    }

    for (int count : counts) {
        if (count != 0) return false;
    }
    return true;
}

// --- Brute-Force/Alternative Solution (Sorting) ---
bool isAnagramBruteForce(string s, string t) {
    if (s.length() != t.length()) return false;
    
    // Sort both strings and compare
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}

int main() {
    string s1 = "anagram";
    string t1 = "nagaram";
    
    cout << "Is Anagram (Optimized): " << isAnagramOptimized(s1, t1) << endl; // Output: 1 (true)
    
    string s2 = "rat";
    string t2 = "car";
    cout << "Is Anagram (Brute Force): " << isAnagramBruteForce(s2, t2) << endl; // Output: 0 (false)
    return 0;
}
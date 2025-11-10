#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Hash Map) ---
char highestFrequencyCharOptimized(const string& str) {
    if (str.empty()) return '\0';

    unordered_map<char, int> freqMap;
    int maxFreq = 0;
    char result = '\0';

    for (char c : str) {
        freqMap[c]++;
        
        if (freqMap[c] > maxFreq) {
            maxFreq = freqMap[c];
            result = c;
        } else if (freqMap[c] == maxFreq) {
            // For ties, choose the character that appears earlier (or based on standard ASCII/lexical order).
            // Here, we maintain the first one encountered that reaches maxFreq.
            // If the problem requires ASCII order for ties, another pass is needed.
        }
    }
    return result;
}

// --- Brute-Force/Alternative Solution (Fixed-Size Array) ---
char highestFrequencyCharBruteForce(const string& str) {
    if (str.empty()) return '\0';

    // Assuming ASCII (256 characters)
    vector<int> counts(256, 0); 
    
    for (char c : str) {
        counts[(int)c]++;
    }
    
    int maxFreq = -1;
    char result = '\0';
    for(int i = 0; i < 256; ++i) {
        if (counts[i] > maxFreq) {
            maxFreq = counts[i];
            result = (char)i;
        }
    }
    return result; // Note: This will prioritize lower ASCII for ties.
}

int main() {
    string s = "programming";
    cout << "Highest Frequency Char (Optimized): " << highestFrequencyCharOptimized(s) << endl; // Output: g or r or m
    return 0;
}
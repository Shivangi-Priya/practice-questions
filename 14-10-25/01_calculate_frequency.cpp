#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


unordered_map<char, int> calculateFrequencyOptimized(const string& str) {
    unordered_map<char, int> freqMap;
    for (char c : str) {
        // Optional: Ignore spaces or convert to lowercase if required
        if (isalpha(c)) { 
             freqMap[c]++;
        }
    }
    return freqMap;
}

vector<int> calculateFrequencyBruteForce(const string& str) {
    // Array size 256 for all possible ASCII characters
    vector<int> counts(256, 0); 
    for (char c : str) {
        counts[(int)c]++;
    }
    return counts;
}


int main() {
    string s = "programming";

    
    unordered_map<char, int> freqMap = calculateFrequencyOptimized(s);
    cout << "Optimized Frequencies:" << endl;
    for (auto const& [key, val] : freqMap) {
        cout << key << ": " << val << endl;
    }

    
    vector<int> counts = calculateFrequencyBruteForce(s);
    cout << "\nBrute Force Frequencies (a-z):" << endl;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (counts[i] > 0) {
            cout << (char)i << ": " << counts[i] << endl;
        }
    }

    return 0;
}
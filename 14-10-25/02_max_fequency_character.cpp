#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

char findMaxOccurringCharOptimized(const string& str) {
    if (str.empty()) return '\0';

    vector<int> counts(256, 0);
    int maxCount = -1;
    char result = '\0';

    for (char c : str) {
        int index = (int)c;
        counts[index]++;
        
       
        if (counts[index] > maxCount) {
            maxCount = counts[index];
            result = c;
        } 
        
    }
    return result;
}

char findMaxOccurringCharBruteForce(const string& str) {
    if (str.empty()) return '\0';

    int maxCount = -1;
    char maxChar = '\0';
    int n = str.length();

    for (int i = 0; i < n; ++i) {
        int currentCount = 0;
        for (int j = 0; j < n; ++j) {
            if (str[i] == str[j]) {
                currentCount++;
            }
        }
        
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxChar = str[i];
        }
    }
    return maxChar;
}


int main() {
    string s = "aabbcdeeeff";

    char maxOpt = findMaxOccurringCharOptimized(s);
    cout << "Optimized - Max occurring character: " << maxOpt << endl; // Output: e

    char maxBrute = findMaxOccurringCharBruteForce(s);
    cout << "Brute Force - Max occurring character: " << maxBrute << endl; // Output: e

    return 0;
}
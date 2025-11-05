#include <iostream>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;


int countWordsOptimized(const string& str) {
    if (str.empty()) return 0;
    
    stringstream ss(str);
    string word;
    int count = 0;

    
    while (ss >> word) {
        count++;
    }
    return count;
}

int countWordsBruteForce(const string& str) {
    enum State { OUT_WORD, IN_WORD };
    State state = OUT_WORD;
    int count = 0;

    for (char c : str) {
        if (isspace(c)) {
            state = OUT_WORD;
        } else if (state == OUT_WORD) {
            state = IN_WORD;
            count++;
        }
    }
    return count;
}


int main() {
    string s = " One two three four ";

    int countOpt = countWordsOptimized(s);
    cout << "Optimized - Word count: " << countOpt << endl; // Output: 4

    int countBrute = countWordsBruteForce(s);
    cout << "Brute Force - Word count: " << countBrute << endl; // Output: 4

    return 0;
}
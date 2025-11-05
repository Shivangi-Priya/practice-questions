
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;


string removeDuplicateOptimized(const string& str) {
    string result = "";
    unordered_set<char> seen;

    for (char c : str) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

string removeDuplicateBruteForce(const string& str) {
    string result = "";
 
    vector<bool> seen(256, false); 

    for (char c : str) {
        int index = (int)c;
        if (!seen[index]) {
            seen[index] = true;
            result += c;
        }
    }
    return result;
}


int main() {
    string s = "geeksforgeeks";

    string resultOpt = removeDuplicateOptimized(s);
    cout << "Optimized Result: " << resultOpt << endl; // Output: geksfor

    string resultBrute = removeDuplicateBruteForce(s);
    cout << "Brute Force Result: " << resultBrute << endl; // Output: geksfor

    return 0;
}
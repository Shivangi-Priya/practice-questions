#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string removeAdjacentDuplicatesOptimized(const string& str, int index) {
    if (index == str.length() - 1) {
        return string(1, str[index]);
    }

    string smallAns = removeAdjacentDuplicatesOptimized(str, index + 1);

    if (str[index] != smallAns[0]) {
        return str[index] + smallAns;
    } else {
        return smallAns;
    }
}

string removeDuplicatesOptimizedWrapper(const string& str) {
    if (str.empty()) return "";
    return removeAdjacentDuplicatesOptimized(str, 0);
}

string removeDuplicatesRecursive(const string& str, int index, string& result, bool seen[256]) {
    if (index == str.length()) {
        return result;
    }

    char c = str[index];
    if (!seen[(int)c]) {
        seen[(int)c] = true;
        result += c;
    }

    return removeDuplicatesRecursive(str, index + 1, result, seen);
}

string removeDuplicatesFinal(const string& str) {
    string result = "";
    bool seen[256] = {false};
    return removeDuplicatesRecursive(str, 0, result, seen);
}

int main() {
    string s1 = "geeksforgeeks";
    
    string final_result = removeDuplicatesFinal(s1);
    cout << "Final Result (All Duplicates Removed): " << final_result << endl; 

    string s2 = "aabccba";
    string adjacent_result = removeDuplicatesOptimizedWrapper(s2);
    cout << "Optimized (Adjacent Duplicates Only): " << adjacent_result << endl; 

    return 0;
}
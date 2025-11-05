
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int sumArrayOptimizedHelper(const vector<int>& arr, int index, int currentSum) {
    if (index == arr.size()) {
        return currentSum; 
    }
   
    return sumArrayOptimizedHelper(arr, index + 1, currentSum + arr[index]);
}

int sumArrayOptimized(const vector<int>& arr) {
    return sumArrayOptimizedHelper(arr, 0, 0);
}

int sumArrayBruteForce(const vector<int>& arr, int n) {
    if (n <= 0) {
        return 0; 
    }
    
    return arr[n - 1] + sumArrayBruteForce(arr, n - 1);
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    int sumOpt = sumArrayOptimized(arr);
    cout << "Optimized Recursive Sum: " << sumOpt << endl; // Output: 15

    int sumBrute = sumArrayBruteForce(arr, arr.size());
    cout << "Brute Force Recursive Sum: " << sumBrute << endl; // Output: 15

    return 0;
}
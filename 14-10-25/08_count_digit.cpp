
#include <iostream>

using namespace std;


int countDigitsOptimized(long long n) {
    if (n == 0) return 1;
    
    n = abs(n);

    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int countDigitsBruteForce(long long n) {
    if (n == 0) return 0; 

    
    n = abs(n);
    
    
    return 1 + countDigitsBruteForce(n / 10);
}


int main() {
    long long n = 123456789;

    cout << "Optimized digit count for " << n << ": " << countDigitsOptimized(n) << endl; // Output: 9

    cout << "Brute Force digit count for " << n << ": " << countDigitsBruteForce(n) << endl; // Output: 9

    return 0;
}
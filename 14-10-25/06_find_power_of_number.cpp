
#include <iostream>

using namespace std;


double powerOptimized(double x, int n) {
    if (n == 0) return 1.0;
    
 
    if (n < 0) {
        x = 1 / x;
        n = abs(n);
    }

    double half = powerOptimized(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

double powerBruteForce(double x, int n) {
    if (n == 0) return 1.0;
    
    
    if (n < 0) {
        x = 1 / x;
        n = abs(n);
    }

    double result = 1.0;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}


int main() {
    double x = 2.0;
    int n = 10;
    cout << "Optimized " << x << "^" << n << ": " << powerOptimized(x, n) << endl; // Output: 1024
    cout << "Brute Force " << x << "^" << n << ": " << powerBruteForce(x, n) << endl; // Output: 1024

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// --- Optimized Solution (Single Pass) ---
int maxProfitOptimized(const vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxP = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxP = max(maxP, price - minPrice);
    }
    return maxP;
}

// --- Brute-Force Solution (Nested Loops) ---
int maxProfitBruteForce(const vector<int>& prices) {
    int maxP = 0;
    for (int i = 0; i < prices.size(); ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
            maxP = max(maxP, prices[j] - prices[i]);
        }
    }
    return maxP;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Optimized): " << maxProfitOptimized(prices) << endl; // Output: 5
    return 0;
}
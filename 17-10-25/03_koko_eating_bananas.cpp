#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Helper function: Check if Koko can finish all piles within H hours at speed K
bool canFinish(const vector<int>& piles, int k, int h) {
    if (k == 0) return false;
    long long totalHours = 0;
    for (int pile : piles) {
        // Equivalent to ceil(pile / k)
        totalHours += (pile + k - 1) / k; 
    }
    return totalHours <= h;
}

// --- Optimized Solution (Binary Search on Answer Space) ---
int minEatingSpeedOptimized(const vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int minK = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFinish(piles, mid, h)) {
            minK = mid;
            high = mid - 1; // Try smaller speed
        } else {
            low = mid + 1; // Must try larger speed
        }
    }
    return minK;
}

// --- Brute-Force Solution (Linear Check) ---
int minEatingSpeedBruteForce(const vector<int>& piles, int h) {
    int maxPile = *max_element(piles.begin(), piles.end());
    for (int k = 1; k <= maxPile; ++k) {
        if (canFinish(piles, k, h)) {
            return k;
        }
    }
    return maxPile;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum Eating Speed (Optimized): " << minEatingSpeedOptimized(piles, h) << endl; // Output: 4
    return 0;
}
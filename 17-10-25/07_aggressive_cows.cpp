#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(const vector<int>& stalls, int c, int min_dist) {
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_pos >= min_dist) {
            count++;
            last_pos = stalls[i];
        }
    }
    return count >= c;
}


int aggressiveCows(vector<int>& stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int max_min_dist = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, c, mid)) {
            max_min_dist = mid;
            low = mid + 1; // Try to find a larger minimum distance
        } else {
            high = mid - 1; // Distance is too large, must decrease
        }
    }
    return max_min_dist;
}

int aggressiveCowsBruteForce(vector<int>& stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int max_dist = stalls.back() - stalls.front();
    
    for (int dist = max_dist; dist >= 1; --dist) {
        if (canPlace(stalls, c, dist)) {
            return dist; 
    }
    return 0;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int c = 3;
    cout << "Largest minimum distance (Optimized): " << aggressiveCows(stalls, c) << endl; 
    return 0;
}
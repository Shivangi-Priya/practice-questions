#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- Optimized Solution (Single Pass with Frequency Arrays) ---
string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    vector<int> secret_counts(10, 0);
    vector<int> guess_counts(10, 0);

    // First pass to find Bulls (exact matches) and count frequencies
    for (size_t i = 0; i < secret.length(); ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secret_counts[secret[i] - '0']++;
            guess_counts[guess[i] - '0']++;
        }
    }

    // Second pass to find Cows (correct digit, wrong position)
    for (int i = 0; i < 10; ++i) {
        // Cows are the minimum of the unmatched counts
        cows += min(secret_counts[i], guess_counts[i]);
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

// --- Brute-Force/Alternative Solution (Using Hash Maps) ---
// This is essentially the same complexity but potentially slower due to map overhead.

int main() {
    string secret = "1807";
    string guess = "7810";
    cout << "Bulls and Cows Hint: " << getHint(secret, guess) << endl; // Output: 1A3B
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// --- Optimized Solution (Using O(1) space with first row/col as markers) ---
void setZeroesOptimized(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    bool firstColHasZero = false;

    // Check if the first column needs to be zeroed
    for (int i = 0; i < R; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    // Use first row and column to mark rows/columns to be zeroed
    for (int i = 0; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark row i
                matrix[0][j] = 0; // Mark col j
            }
        }
    }

    // Zero out cells based on the markers (excluding the first row/col)
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (matrix[0][0] == 0) {
        for (int j = 1; j < C; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed (check based on the flag)
    if (firstColHasZero) {
        for (int i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
}

// --- Brute-Force/Alternative Solution (Using O(M+N) space) ---
void setZeroesBruteForce(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    unordered_set<int> zeroRows;
    unordered_set<int> zeroCols;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (zeroRows.count(i) || zeroCols.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroesOptimized(matrix);
    cout << "Matrix after zeroing: " << endl;
    for (const auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl; // Output: 1 0 1 \n 0 0 0 \n 1 0 1
    }
    return 0;
}
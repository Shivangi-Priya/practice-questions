#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Recursive Insert/Search) ---
BSTNode* insert(BSTNode* root, int val) {
    if (root == NULL) {
        return new BSTNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(BSTNode* root, int val) {
    if (root == NULL) return false;
    if (root->val == val) return true;
    
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// --- Brute-Force/Alternative Solution (Iterative Search) ---
bool searchIterative(BSTNode* root, int val) {
    BSTNode* current = root;
    while (current != NULL) {
        if (current->val == val) return true;
        if (val < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

int main() {
    BSTNode* root = NULL;
    vector<int> elements = {50, 30, 70, 20, 40, 60, 80};
    for (int val : elements) {
        root = insert(root, val);
    }

    int searchVal = 40;
    cout << "Search for " << searchVal << " (Optimized): " << search(root, searchVal) << endl; // Output: 1 (true)
    
    int searchVal2 = 10;
    cout << "Search for " << searchVal2 << " (Brute Force): " << searchIterative(root, searchVal2) << endl; // Output: 0 (false)
    return 0;
}
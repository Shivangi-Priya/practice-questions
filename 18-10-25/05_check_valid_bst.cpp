#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Recursive with Range/Bounds) ---
bool checkValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (node == NULL) return true;

    // Check if current node value is within the valid range
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    // Check left subtree: Max bound is updated to current node's value
    // Check right subtree: Min bound is updated to current node's value
    return checkValidBSTHelper(node->left, minVal, node->val) &&
           checkValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBSTOptimized(TreeNode* root) {
    return checkValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}



int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << "Is Valid BST (Optimized): " << isValidBSTOptimized(root) << endl; // Output: 1 (true)

    TreeNode* invalidRoot = new TreeNode(5);
    invalidRoot->left = new TreeNode(1);
    invalidRoot->right = new TreeNode(4);
    invalidRoot->right->left = new TreeNode(3);
    invalidRoot->right->right = new TreeNode(6);

    cout << "Is Valid BST (Invalid Case): " << isValidBSTOptimized(invalidRoot) << endl; // Output: 0 (false)
    return 0;
}
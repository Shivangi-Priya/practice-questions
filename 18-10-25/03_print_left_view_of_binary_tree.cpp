#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Optimized Solution (Level Order Traversal / BFS) ---
vector<int> leftSideViewOptimized(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            // The first node of every level is the left view node
            if (i == 0) {
                result.push_back(current->val);
            }

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    return result;
}

// --- Brute-Force/Alternative Solution (Recursive DFS) ---
void leftSideViewBruteForce(TreeNode* root, vector<int>& result, int level, int& maxLevel) {
    if (root == NULL) return;

    if (level > maxLevel) {
        result.push_back(root->val);
        maxLevel = level;
    }

    leftSideViewBruteForce(root->left, result, level + 1, maxLevel);
    leftSideViewBruteForce(root->right, result, level + 1, maxLevel);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->right->right = new TreeNode(15);
    root->right->left = new TreeNode(1);

    vector<int> result = leftSideViewOptimized(root);
    cout << "Left View (Optimized): ";
    for (int x : result) cout << x << " "; // Output: 10 2 7
    cout << endl;
    return 0;
}
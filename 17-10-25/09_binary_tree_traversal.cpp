#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Recursive Traversal (Standard/Brute-Force) ---
void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// --- Optimized Traversal (Level Order - BFS) ---
void levelOrder(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// --- Space-Efficient Traversal (Morris Traversal for Inorder) ---
void morrisInorder(TreeNode* root) {
    TreeNode* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->val << " ";
            current = current->right;
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Create link
                predecessor->right = current;
                current = current->left;
            } else {
                // Remove link, print, and move right
                predecessor->right = NULL;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder (Recursive): "; preorder(root); cout << endl;
    cout << "Inorder (Recursive): "; inorder(root); cout << endl;
    cout << "Postorder (Recursive): "; postorder(root); cout << endl;
    cout << "Level Order (BFS): "; levelOrder(root); cout << endl;
    cout << "Morris Inorder: "; morrisInorder(root); cout << endl; // Output: 4 2 5 1 3 
    
    return 0;
}
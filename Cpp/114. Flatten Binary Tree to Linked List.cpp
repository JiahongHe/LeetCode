/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* prev;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (prev) prev->right = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        prev = root;
        flatten(left);
        flatten(right);
    }
};
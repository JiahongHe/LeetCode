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
    bool validBST(TreeNode* root, long low, long high) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;
        return validBST(root->left, low, root->val) && validBST(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root && (!root->left && !root->right)) return true;
        return validBST(root, LONG_MIN, LONG_MAX);
    }
};
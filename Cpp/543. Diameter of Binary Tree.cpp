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
    int maxPath = 0;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        maxPath = max(maxPath, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return maxPath;
    }
};
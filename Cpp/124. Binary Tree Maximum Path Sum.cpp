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
    int maxSum = INT_MIN;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
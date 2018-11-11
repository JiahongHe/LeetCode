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
    int findPath(TreeNode* root, int sum) {
        int counter = 0;
        if (!root) return counter;
        if (root->val == sum)
            counter++;
        int left = findPath(root->left, sum - root->val);
        int right = findPath(root->right, sum - root->val);
        return counter + left + right;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
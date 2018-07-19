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
public:
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = buildTree(nums, l, m - 1);
        node->right = buildTree(nums, m + 1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
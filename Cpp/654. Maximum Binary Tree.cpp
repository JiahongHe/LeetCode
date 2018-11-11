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
    int findMaxElement(vector<int>& nums, int left, int right) {
        int maxInd = -1;
        int maxNum = INT_MIN;
        for (int i = left; i < min(right + 1, (int)nums.size()); i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxInd = i;
            }
        }
        return maxInd;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int maxInd = findMaxElement(nums, left, right);
        TreeNode* root = new TreeNode(nums[maxInd]);
        root->left = constructMaximumBinaryTree(nums, left, maxInd - 1);
        root->right = constructMaximumBinaryTree(nums, maxInd + 1, right);
        return root;
    } 
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return nullptr;
        return constructMaximumBinaryTree(nums, 0, N - 1);
    }
};
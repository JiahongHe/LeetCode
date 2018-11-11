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
    void findPath(TreeNode* root, int sum, vector<int>& curPath, vector<vector<int>>& result) {
        if (!root) return;
        int curSum = sum - root->val;
        curPath.push_back(root->val);
        if (curSum == 0 && !root->left && !root->right) result.push_back(curPath);
        findPath(root->left, curSum, curPath, result);
        findPath(root->right, curSum, curPath, result);
        curPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> curPath;
        findPath(root, sum, curPath, result);
        return result;
    }
};
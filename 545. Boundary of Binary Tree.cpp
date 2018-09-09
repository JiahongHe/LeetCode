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
    void addBoundary (TreeNode* root, vector<int>& res, bool isLeftBoundary, bool isRightBoundary) {
        if (!root) return;
        if (isLeftBoundary) res.push_back(root->val);
        addBoundary (root->left, res, isLeftBoundary, isRightBoundary && root->right == NULL);
        if (!isLeftBoundary && !isRightBoundary && root->left == NULL && root->right == NULL) res.push_back(root->val);
        addBoundary (root->right, res, isLeftBoundary && root->left == NULL, isRightBoundary);
        if (isRightBoundary) res.push_back(root->val);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        result.push_back(root->val);
        addBoundary (root->left, result, true, false);
        addBoundary (root->right, result, false, true);
        return result;
    }
};
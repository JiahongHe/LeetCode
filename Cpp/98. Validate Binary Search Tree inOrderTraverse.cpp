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
    void inOrder(TreeNode* root, vector<int>& path) {
        if (!root) return;
        inOrder(root->left, path);
        path.push_back(root->val);
        inOrder(root->right, path);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> path;
        if (!root) return true;
        inOrder(root, path);
        for (int i = 0; i < path.size() - 1; i++) {
            if (path[i] >= path[i + 1]) return false;
        }
        return true;
    }
};
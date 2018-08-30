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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            while (count > 0) {
                auto node = q.front();
                q.pop();
                count--;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (count == 0) result.push_back(node->val);
            }
        }
        return result;
    }
};
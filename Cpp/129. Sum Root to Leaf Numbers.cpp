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
    int helper(TreeNode* node, vector<int> path) {
        if (!(node ->left || node->right)) {
            int res = 0;
            for (int i = 0; i < path.size(); i++) {
                res += path[i] * pow(10, path.size() - i);
            }
            res += node->val;
            return res;
        }
        path.push_back(node->val);
        int left = 0;
        int right = 0;
        if (node->left) left = helper(node->left, path);
        if (node->right) right = helper(node->right, path);
        return (left + right);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        vector<int> path;
        int sum = helper(root, path);
        return sum;
    }
};
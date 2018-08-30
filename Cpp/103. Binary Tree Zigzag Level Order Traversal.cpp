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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        int odd = 1;
        while (!s1.empty() || !s2.empty()) {
            cout << s1.size() << " " << s2.size() << endl;
            odd = -odd;
            vector<int> row;
            if (odd < 0) {
                while (!s1.empty()) {
                    auto node = s1.top();
                    s1.pop();
                    if (node->left) s2.push(node->left);
                    if (node->right) s2.push(node->right);
                    row.push_back(node->val);
                }
            }
            if (odd > 0) {
                while (!s2.empty()) {
                    auto node = s2.top();
                    s2.pop();
                    if (node->right) s1.push(node->right);
                    if (node->left) s1.push(node->left);
                    row.push_back(node->val);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};
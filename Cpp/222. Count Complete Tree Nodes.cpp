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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int hl = 1;
        int hr = 1;
        while(left) {
            hl++;
            left = left->left;
        }
        while(right) {
            hr++;
            right = right->right;
        }
        if (hl == hr) return pow(2, hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
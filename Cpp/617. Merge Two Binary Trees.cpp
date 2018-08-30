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
    TreeNode* merge(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        if (t1 && !t2) return t1;
        if (t2 && !t1) return t2;
        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = merge(t1->left, t2->left);
        node->right = merge(t1->right, t2->right);
        return node;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};
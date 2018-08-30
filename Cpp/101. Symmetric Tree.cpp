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
    bool helper(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) return true;
        if (!node1 || !node2) return false;
        if (node1->val != node2->val) return false;
        bool con1 = helper(node1->left, node2->right);
        bool con2 = helper(node1->right, node2->left);
        return con1 && con2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
        
    }
};
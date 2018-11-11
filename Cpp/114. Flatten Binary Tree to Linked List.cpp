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
    void traverse(TreeNode* node, queue<TreeNode*>& nodes) {
        if (!node) return;
        nodes.push(node);
        traverse(node->left, nodes);
        traverse(node->right, nodes);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> nodes;
        traverse(root, nodes);
        TreeNode* prev = nodes.front();
        prev->left = NULL;
        prev->right = NULL;
        nodes.pop();
        while (!nodes.empty()) {
            TreeNode* curNode = nodes.front();
            curNode->left = NULL;
            curNode->right = NULL;
            nodes.pop();
            prev->right = curNode;
            prev = prev->right;
        }
    }
};
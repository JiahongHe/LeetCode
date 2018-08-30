/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int>::iterator it;
    vector<int> inOrder;
    
    void inOrderTraverse(TreeNode *root, vector<int>& inOrder) {
        if (!root) return;
        inOrderTraverse(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraverse(root->right, inOrder);
    }
public:
    BSTIterator(TreeNode *root) {
        inOrderTraverse(root, inOrder);
        it = inOrder.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return it < inOrder.end();
    }

    /** @return the next smallest number */
    int next() {
        return *(it++);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        if not root:
            return True
        
        self.flag = True
        def DFS(node, depth):
            if not self.flag:
                return
            l = depth
            r = depth
            if node.left:
                l = DFS(node.left, depth + 1)
            if node.right:
                r = DFS(node.right, depth + 1)
            if not node.left and not node.right:
                return depth
            
            if not self.flag:
                return 
            else:
                if l - r > 1 or r - l > 1:
                    self.flag = False
                    return 
            return max(l, r)
        
        DFS(root, 1)
        return self.flag
            
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        def DFS(node, depth):
            l = float('inf')
            r = float('inf')
            if node.left:
                l = DFS(node.left, depth + 1)
            if node.right:
                r = DFS(node.right, depth + 1)
            if (not node.left and not node.right):
                return depth
            return min(l, r)
        
        d = DFS(root, 1)
        return d
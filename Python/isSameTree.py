# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q:
            return True
        if not p or not q:
            return False
        
        self.flag = True
        def DFS(p, q):
    
            if not self.flag:
                return
            
            if (p.val != q.val):
                self.flag = False
                return
            
            if not p.left or not q.left:
                if not(not p.left and not q.left):
                    self.flag = False
                    return
            else:
                DFS(p.left, q.left)
                
            if not p.right or not q.right:
                if not(not p.right and not q.right):
                    self.flag = False
                    return
            else:
                DFS(p.right, q.right)
        DFS(p, q)
        return self.flag
            
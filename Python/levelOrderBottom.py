# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import queue
class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        parent_nodes = [root]
        child_nodes = []
        vals = []
        val = []
        while len(parent_nodes) > 0:
            for node in parent_nodes:
                if node.left is not None:
                    child_nodes.append(node.left)
                if node.right is not None:
                    child_nodes.append(node.right)
                val.append(node.val)
            vals.append(val)
            val = []
            parent_nodes = child_nodes
            child_nodes = []
        vals = vals[::-1]
        return vals
        
        
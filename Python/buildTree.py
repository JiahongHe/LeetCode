# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, nums, l, r):
        if l > r:
            return None
        m = (l + r) // 2
        node = TreeNode(nums[m])
        node.left = self.buildTree(nums, l, m - 1)
        node.right = self.buildTree(nums, m + 1, r)
        return node
        
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if nums is None:
            return None
        return self.buildTree(nums, 0, len(nums) - 1)
class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        k = k % N
        nums_1 = nums[-k:] 
        nums_2 = nums[: N - k]
        nums[:k] = nums_1
        nums[k:] = nums_2
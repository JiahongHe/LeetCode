class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        dp = [nums[0]]
        for i in range(1, len(nums)):
            dp.append(nums[i] + max(dp[i-1], 0))
        return max(dp)
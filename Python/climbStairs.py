class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0, 1, 2]
        if n < len(dp):
            return dp[n]
        for i in range(3, n+1):
            dp.append(dp[i - 1] + dp[i - 2])
        return dp[n]
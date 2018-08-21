class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        N = len(s)
        dp = [[0 for _ in range(N)] for _ in range(N)]
        for i in range(N):
            dp[i][i] = True
        max_len = 0
        start = 0
        end = 0
        for i in range(N - 2, -1, -1):
            for j in range(i+1, N):
                if (s[i] == s[j] and (dp[i + 1][j - 1] or j == i + 1)):
                    dp[i][j] = True
                    length = j - i + 1
                    if length > max_len:
                        max_len = length
                        start = i
                        end = j
                else:
                    dp[i][j] = False
        return s[start: end + 1]
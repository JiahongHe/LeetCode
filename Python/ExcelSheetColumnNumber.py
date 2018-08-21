class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        N = len(s)
        res = 0
        for i in range(N):
            res += (ord(s[i]) - 64) * (26 ** (N - 1 - i))
        return res
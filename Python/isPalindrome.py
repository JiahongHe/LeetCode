class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x_str = str(x)
        N = len(x_str)
        mid = N // 2 
        for i in range(0, mid):
            if (x_str[i] != x_str[N - i - 1]):
                return False
        return True
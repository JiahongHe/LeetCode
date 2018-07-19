class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        count = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == " " and count == 0:
                continue
            if s[i] == " " and count != 0:
                return count
            count += 1
        return count
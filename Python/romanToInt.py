class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        value = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        
        length = len(s)
        result = 0
        pre_val = 0
        for i in range(length-1,-1,-1):
            cur_val = value[s[i]]
            if pre_val > cur_val:
                result -= cur_val
            if cur_val >= pre_val:
                result += cur_val
            pre_val = cur_val
        return result
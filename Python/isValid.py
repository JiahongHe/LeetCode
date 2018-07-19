class Solution:
    def isValid(self, string):
        """
        :type s: str
        :rtype: bool
        """
        dic = {
            '(': ')', 
            '{': '}', 
            '[': ']'
        }
        stack = []
        for s in string:
            if s in dic.keys():
                stack.append(s)
            else:
                try:
                    if dic[stack[-1]] == s:
                        stack.pop()
                    else:
                        return False
                except:
                    return False
        if len(stack) != 0:
            return False
        return True
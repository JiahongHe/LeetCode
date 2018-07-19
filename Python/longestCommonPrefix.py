class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        def lcp(strs):
            prefix = ""
            cur = ""
            if len(strs) == 0:
                return ""
            try:
                for i in range(len(strs[0])):
                    cur = strs[0][i]
                    for char in strs:
                        if cur != char[i]:
                            return prefix
                    prefix += cur
            except:
                return prefix
        if not strs:
            return ""
        else:
            return lcp(strs) 
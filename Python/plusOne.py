class Solution:
    def (self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while digits[i] + 1 > 9:
            digits[i] = 0
            if i == 0:
                digits.insert(0, 1)
                return digits
            i -= 1
        digits[i] += 1
        return digits
            
        
        
        """
        Original Solution 
        s = ""
        ans = []
        for d in digits:
            s += str(d)
        num = str(int(s) + 1)
        for n in num:
            ans.append(int(n))
        return ans
        */
        """
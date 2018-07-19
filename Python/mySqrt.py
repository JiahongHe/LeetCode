class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left, right = 0, x
        mid = (left + right) // 2
        while right >= left:
            if mid**2 <= x and (mid+1)**2 > x:
                return mid
            elif mid**2 > x:
                right = mid - 1
                mid = (left + right) // 2
            elif (mid+1)**2 <= x:
                left = mid + 1
                mid = (left + right) // 2
        return 
class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        l = 0
        r = 0
        k = 0
        while (l < m + k and r < n):
            if nums1[l] <= nums2[r]:
                l += 1
            else:
                for i in range(m + k - l):
                    nums1[m + k - i] = nums1[m + k - 1 - i]
                    
                nums1[l] = nums2[r]
                r += 1
                l += 1
                k += 1
        while (l >= m + k and r < n):
            for i in range(m + n - l):
                nums1[l] = nums2[r]
                r += 1
                l += 1
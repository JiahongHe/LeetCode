class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if (len(nums) == 0):
            return 0
        if nums[-1] < target:
            return len(nums)
        if nums[0] > target:
            return 0
        
        l, r = 0, len(nums) - 1
        m = (l + r) // 2
        while l < r - 1:
            if (nums[m] == target):
                return m
            elif (nums[m] < target) :
                l = m
            else:
                r = m
            m = (l + r) // 2
        if nums[m] < target:
            return m + 1
        else:
            return m
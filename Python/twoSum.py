class Solution:
    def twoSum(self, num, target):
        map = {}
        for i in range(len(num)):
            if num[i] not in map:
                map[target - num[i]] = i 
            else:
                return map[num[i]], i
        return -1, -1

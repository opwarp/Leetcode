# 213. House Robber II.py
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) < 2:
            return nums[0]
        preMax1, curMax1 = 0, 0
        for cur in nums[1:]:
            tmp = curMax1
            curMax1 = max(preMax1+cur, curMax1)
            preMax1 = tmp
        preMax2, curMax2 = 0, 0
        for cur in nums[:-1]:
            tmp = curMax2
            curMax2 = max(preMax2+cur, curMax2)
            preMax2 = tmp
        return max(curMax1, curMax2)
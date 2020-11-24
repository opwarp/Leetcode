# 198. House Robber.py
# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         if len(nums) == 0:
#             return 0
#         if len(nums) < 3:
#             return max(nums)
#         if len(nums) == 3:
#             return max(nums[0]+nums[2], nums[1])
#         dp = [nums[0], nums[1], nums[2]+nums[0]] + ([0] * (len(nums) - 3))
#         for i in range(3, len(nums)):
#             dp[i] = nums[i] + max(dp[i-2], dp[i-3])
#         print(dp)
#         return max(dp[-1], dp[-2])
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        lastMax, curMax = 0, 0
        for cur in nums:
            temp = curMax
            curMax = max(cur + lastMax, curMax)
            lastMax = temp 
        return curMax
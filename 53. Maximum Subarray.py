# 53. Maximum Subarray.py
class Solution: #O(n)
    def maxSubArray(self, nums: List[int]) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        lmin = 0
        summary = 0
        ret = nums[0]
        for i in nums:
            if ret <= (i + summary - lmin): # find maxium difference between current summary(i + last summary) and last lmin
                ret = i + summary - lmin
            summary+=i # record summary by last i
            if summary <= lmin:
                lmin = summary # record the minium summary by last i
        return ret

### divide and conquer
class Solution: #O(nlogn)
    def divconq(self, start, end, nums):
        if start == end:
            return nums[start]
        mid = (end + start) // 2
        maxL, maxR = -float("inf"), -float("inf")
        accu = 0
        for i in range(mid, start-1, -1): # iter start...mid-1
            accu += nums[i]
            if accu > maxL:
                maxL = accu
        accu = 0
        for i in range(mid+1, end+1): # iter mid...len-1
            accu += nums[i]
            if accu > maxR:
                maxR = accu
        return max(
            maxL+maxR,
            self.divconq(start, mid, nums),
            self.divconq(mid+1, end, nums)
        )
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return -2147483648
        return self.divconq(0, len(nums)-1, nums)
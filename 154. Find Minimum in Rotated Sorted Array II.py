# 154. Find Minimum in Rotated Sorted Array II.py
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) -1
        if l >= r:
            return nums[0]
        while l < r:
            mid = (r + l)  // 2
            if nums[mid] > nums[mid+1]:
                return nums[mid+1]
            elif nums[mid] > nums[r]:
                l = mid
            elif nums[mid] < nums[r]:
                r = mid
            else:
                r-=1
                
        return nums[0]
                 
        
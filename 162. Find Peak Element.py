162. Find Peak Element.py
class Solution(object):
    def findPeakElement(self, nums):
        nums = [float('-inf')] + nums + [float('-inf')]
        l, r = 0, len(nums)-1
        while l != r:
            idx = (l + r)//2
            print(idx)
            if nums[idx]>nums[idx-1] and nums[idx]>nums[idx+1]:
                return idx-1
            elif nums[idx]<nums[idx-1]:
                r = idx-1
            elif nums[idx]<nums[idx+1]:
                l = idx+1
            else:
                l=r
        return l-1
                
        """
        :type nums: List[int]
        :rtype: int
        """
        
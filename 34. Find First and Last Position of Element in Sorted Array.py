# 34. Find First and Last Position of Element in Sorted Array.py
class Solution:
    def searchLeft(self, nums, target, pos):
        if len(nums) == 1:
            if nums[0] == target:
                return pos
            else:
                return -1
        mid = len(nums) // 2
    
        if nums[mid-1] == target and nums[mid] == target:
            return self.searchLeft(nums[:mid], target, pos)
        if nums[mid-1] != target and nums[mid] == target:
            return pos+mid
        if nums[mid-1] == target and nums[mid] != target:
            return pos+mid-1
        if nums[mid-1] != target and nums[mid] != target:
            if target  < nums[mid-1]:
                return self.searchLeft(nums[:mid], target, pos)
            elif target > nums[mid]:
                return self.searchLeft(nums[mid:], target, pos+mid)
            else:
                return -1
        return -1
    
    def searchRight(self, nums, target, pos):
        if len(nums) == 1:
            if nums[0] == target:
                return pos
            else:
                return -1
        mid = len(nums) // 2
       
        if nums[mid-1] == target and nums[mid] == target:
            return self.searchRight(nums[mid:], target, pos+mid)
        if nums[mid-1] == target and nums[mid] != target:
            return pos+mid-1
        if nums[mid-1] != target and nums[mid] == target:
            return pos+mid
        if nums[mid-1] != target and nums[mid] != target:
            if target  < nums[mid-1]:
                return self.searchRight(nums[:mid], target, pos)
            elif target > nums[mid]:
                return self.searchRight(nums[mid:], target, pos+mid)
            else:
                return -1
        return -1
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1,-1]
        if len(nums) == 1:
            if nums[0] == target:
                return [0,0]
            else:
                return [-1,-1]
        mid = len(nums) // 2
        if nums[mid-1] == target and nums[mid] == target:
            return [self.searchLeft(nums[:mid], target, 0), self.searchRight(nums[mid:], target, mid)]
        if nums[mid-1] == target and nums[mid] != target:
            return [self.searchLeft(nums[:mid], target, 0), mid-1]
        if nums[mid-1] != target and nums[mid] == target:
            return [mid, self.searchRight(nums[mid:], target, mid)]
        if nums[mid-1] != target and nums[mid] != target:
            if target  < nums[mid-1]:
                return self.searchRange(nums[:mid], target)
            elif target > nums[mid]:
                [l, r] = self.searchRange(nums[mid:], target)
                if l==-1 and r==-1:
                    return [-1, -1]
                return [l+mid, r+mid]
            else:
                return [-1, -1]
# 33. Search in Rotated Sorted Array.py
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        newNums = nums
        idx = 0
        while True:
            if len(newNums) == 0:
                print(newNums)
                return -1
            mid = len(newNums) // 2
            if newNums[mid] <= newNums[-1]: # find the half than exclude the pivot
                if target >= newNums[mid] and target <= newNums[-1]: # check if the target is in the that half
                    newNums = newNums[mid:]
                    idx = idx+mid
                else: # if not, it must be in another half
                    newNums = newNums[:mid]
            else: # find the half than exclude the pivot
                if target >= newNums[0] and target <= newNums[mid-1]: # check if the target is in the that half
                    newNums = newNums[:mid]
                else: # if not, it must be in another half
                    newNums = newNums[mid:] 
                    idx = idx+mid
            if len(newNums) == 1:
                if newNums[0] == target:
                    return idx
                else:
                    return -1
# 81. Search in Rotated Sorted Array II.py
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if len(nums) == 0:
            return False
        while True:
            if len(nums) == 1:
                break
            mid = len(nums) // 2
            if nums[0] < nums[-1]:
                if target >= nums[mid]:
                    nums = nums[mid:]
                else:
                    nums = nums[:mid]
            elif nums[mid] == nums[0] and nums[mid] == nums[-1]:
                return (self.search(nums[:mid], target) | self.search(nums[mid:], target))
            else:
                if nums[mid] > nums[-1]:
                    if target >= nums[0] and target <= nums[mid]:
                        nums = nums[:mid+1]
                    else:
                        nums = nums[mid:]
                else:
                    if target >= nums[mid] and target <= nums[-1]:
                        nums = nums[mid:]
                    else:
                        nums = nums[:mid]
        return nums[0] == target
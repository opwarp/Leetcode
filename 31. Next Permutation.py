# 31. Next Permutation.py
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        idx = l - 2
        if idx < 0:
            return
        while idx >= 0:
            for i in range(idx+1, l):
                if nums[i] > nums[idx]:
                    nums[idx], nums[i] = nums[i], nums[idx]
                    return
            temp = nums[idx]
            del nums[idx]
            nums.append(temp)
            idx -= 1
        return
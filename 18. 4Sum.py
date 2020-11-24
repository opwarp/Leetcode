18. 4Sum.py
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()
        # print(nums)
        for i, n in enumerate(nums):
            if i!=0 and nums[i]==nums[i-1]:
                continue
            for j, m in enumerate(nums[i+1:]):
                if j!=0 and nums[i+1+j]==nums[i+1+j-1]:
                    continue
                l, r = i+j+2, len(nums) - 1
                curTarg = target - n - m
                while l < r:
                    # print([n,m,nums[l],nums[r]])
                    if curTarg-nums[l]-nums[r] < 0 or (r!=len(nums)-1 and nums[r]==nums[r+1]):
                        r-=1
                    elif curTarg-nums[l]-nums[r] > 0 or (l!=i+j+2 and nums[l]==nums[l-1]):
                        l+=1
                    else:
                        res.append([n, m, nums[l], nums[r]])
                        l+=1
                        r-=1
        return res
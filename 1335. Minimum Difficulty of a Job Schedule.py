# 1335. Minimum Difficulty of a Job Schedule.py 
# O(nnd) S(nnd) base on the dp size, all recursion are to fill up dp[n][d] with getMinDiffSum( O(n) )
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d or n == 0:
            return -1
        dp= [ [-1]*n  for i in range(d+1) ]
        def getMinDiffSum(i, d):
            if d == 1: # all jobs are done in onde day, return max diff
                return max(jobDifficulty[i:])
            if dp[d][i] > 0:
                return dp[d][i]   
            minDiffSum = float('inf')
            diffBefJ = -1
            for j in range(i, n-d+1):
                # seperate diffs into two parts: one for current day, one for left days
                diffBefJ = max(diffBefJ, jobDifficulty[j])
                diffAftJ = getMinDiffSum(j+1, d-1)
                minDiffSum = min(minDiffSum, diffBefJ + diffAftJ)
                
            
            dp[d][i] = minDiffSum
            return minDiffSum
        
        return getMinDiffSum(0, d)
            

# 712. Minimum ASCII Delete Sum for Two Strings.py
class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        r = len(s2)
        c = len(s1)
        dp = [[0]*(c+1) for i in range(r+1)]
        for i in range(r):
            for j in range(c):
                if s1[j] == s2[i]:
                    dp[i+1][j+1] = dp[i][j] + ord(s1[j])
                else:
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
        sum = 0
        for i in range(r):
            sum += ord(s2[i])
        for j in range(c):
            sum += ord(s1[j])
        return sum - 2*dp[r][c]
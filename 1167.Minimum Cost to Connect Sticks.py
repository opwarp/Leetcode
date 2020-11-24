# 1167 Minimum Cost to Connect Sticks.py
class Solution:
    """
    @param sticks: the length of sticks
    @return: Minimum Cost to Connect Sticks
    """
    def MinimumCost(self, sticks):
        # write your code here
        if len(sticks) == 1:
            return 0
        sticks.sort()
        totl = 0
        while len(sticks) > 1:
            a = sticks.pop(0)
            b = sticks.pop(0)
            c = a + b
            totl = totl + c
            for i, stick in enumerate(sticks):
                if c < stick:
                    sticks = sticks[:i] + [c] + sticks[i:]
                    break
            if len(sticks) == 0 or c >= sticks[-1]:
                sticks = sticks + [c]
        return totl
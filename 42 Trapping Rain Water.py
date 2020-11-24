# 42 Trapping Rain Water.py
class Solution:
    def trap(self, height: List[int]) -> int:
        maxl = 0
        full = []
        for h in height:
            maxl = max(maxl, h)
            full.append(maxl)
        maxr = 0
        for i, h in enumerate(reversed(height)):
            maxr = max(maxr, h)
            full[-i-1] = maxr
            if h == maxl:
                break
        water = 0
        for i in range(len(height)):
            water += full[i] - height[i]
        return water
        
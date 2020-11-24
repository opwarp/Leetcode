305.Number of Islands II.py
"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""

class Solution:
    """
    @param n: An integer
    @param m: An integer
    @param operators: an array of point
    @return: an integer array
    """
    def numIslands2(self, n, m, operators):
        res = []
        islands = []
        for op in operators:
            
            newIslands = []
            mergedIsland = {(op.x, op.y)}
            for island in islands:
                if (op.x+1, op.y) in island or (op.x-1, op.y) in island or (op.x, op.y+1) in island or (op.x, op.y-1) in island or (op.x, op.y) in island :
                    mergedIsland = mergedIsland | island
                else:
                    newIslands.append(island)
            newIslands.append(mergedIsland)
            islands = newIslands
            res.append(len(islands))
        return res
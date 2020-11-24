# 994. Rotting Oranges.py
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        x = len(grid)
        y = len(grid[0])
        day = 0
        while True:
            fresh = 0
            rotten = False
            for i in range(x):
                for j in range(y):
                    if grid[i][j] == 2:
                        if j != 0 and grid[i][j-1] == 1:
                            grid[i][j-1] = 2
                            rotten = True
                        if i != 0 and grid[i-1][j] == 1:
                            grid[i-1][j] = 2
                            rotten = True
                        if i != x-1 and grid[i+1][j] == 1:
                            grid[i+1][j] = 3
                            rotten = True
                        if j != y-1 and grid[i][j+1] == 1:
                            grid[i][j+1] = 3
                            rotten = True
                    if grid[i][j] == 3:
                        grid[i][j] = 2
                    fresh += grid[i][j] == 1
            if rotten:
                day += 1
            elif fresh != 0:
                return -1
            else:
                return day
        
            

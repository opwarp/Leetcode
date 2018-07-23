class Solution(object):
    def numIslands(self, grid):
        def sink(i,j):
            grid[i][j] ='0'
            for x,y in zip([i,i,i+1,i-1],[j+1,j-1,j,j]):
                if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y] =='1':sink(x,y)
            return 1
        return 0 if not grid else sum(
            sink(x,y) if grid[x][y]=='1' else 0 
            for x in range(len(grid)) 
            for y in range(len(grid[0])))
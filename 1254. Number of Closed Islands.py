class Solution:
    def dfs(self, grid, x, y, w, h):
        if grid[y][x] == 1 or grid[y][x] == 2:
            return # visited or water
        if x == 0 or x == w-1 or y == 0 or y== h-1:
            self.isClosedIsland = 0 # connected to edge
        grid[y][x] = 2 # mark [x,y] is visited
        if x > 0:
            self.dfs(grid, x-1, y, w, h)
        if x < w-1:
            self.dfs(grid, x+1, y, w, h)
        if y > 0:
            self.dfs(grid, x, y-1, w, h)
        if y < h-1:
            self.dfs(grid, x, y+1, w, h)
        return
        
    def closedIsland(self, grid: List[List[int]]) -> int:
        import queue
        ans = 0
        h = len(grid)
        w = len(grid[0])
        for x in range(w):
            for y in range(h):
                if grid[y][x] == 0:
                    self.isClosedIsland = 1
                    self.dfs(grid, x, y, w, h)
                    ans += self.isClosedIsland
        return ans
                
            
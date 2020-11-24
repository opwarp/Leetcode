# 695. Max Area of Island.py
class Solution:
    def bfs(self, g, i, j, r, c):
        dq = collections.deque([[i, j]])
        while dq:
            i, j = dq.popleft()
            if i<0 or i>=r or j<0 or j>=c or g[i][j] == 0 :
                continue
            print(f'{i},{j}')
            self.size += 1
            g[i][j] = 0
            dq.append([i+1, j])
            dq.append([i, j+1])
            dq.append([i-1, j])
            dq.append([i, j-1])
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), 0
        ret = 0
        if row > 0:
            col = len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j]:
                    self.size = 0
                    self.bfs(grid, i,j,row, col)
                    if self.size > ret:
                        ret = self.size
        return ret
                    
        
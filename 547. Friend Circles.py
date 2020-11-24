# 547. Friend Circles.py

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        nRow = len(M)
        if nRow < 0:
            return 0
        nCol = len(M[0])
        res = 0
        def dfs(i): # mark friends relationship of ith person to as -1
            if M[i][i] == -1:
                return
            M[i][i] = -1
            for j in range(nCol):
                if M[i][j] == 1: 
                    M[i][j] = -1
                    M[j][i] = -1
                    dfs(j)
            return

        for i in range(nRow):
            if M[i][i] == 1: #one to one is stil a cycle
                dfs(i) #dfs finished, mark a cycle all -1
                res += 1
        return res
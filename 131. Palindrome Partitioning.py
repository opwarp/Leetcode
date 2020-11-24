# 131. Palindrome Partitioning.py
# dp n!
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = [list(s)]
        idx = 0
        startList = [0]
        while idx != len(res):
            curList = res[idx]
            start = startList[idx]
            for i in range(start, len(curList)-1):
                if curList[i] == curList[i+1] and len(curList[i]) == 1:
                    res.append(curList[:i]+[curList[i]+curList[i+1]]+curList[i+2:])
                    startList.append(max(i-1, 0))
            for i in range(start, len(curList)-2):
                if curList[i] == curList[i+2] and len(curList[i]) == 1:
                    res.append(curList[:i]+[curList[i]+curList[i+1]+curList[i+2]]+curList[i+3:])
                    startList.append(max(i-1, 0))
            idx += 1
            # print (len(res))
        return res

# dfs
class Solution:
    def partition(self, s):
        res = []
        self.dfs(s, [], res)
        return res

    def dfs(self, s, path, res):
        if not s:
            res.append(path)
            return
        for i in range(1, len(s)+1):
            if self.isPal(s[:i]):
                self.dfs(s[i:], path+[s[:i]], res)
        
    def isPal(self, s):
        return s == s[::-1]
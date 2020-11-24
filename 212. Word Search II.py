# 212. Word Search II.py
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie={}
        for w in words:
            t=trie
            for c in w:
                if c not in t:
                    t[c]={}
                t=t[c]
            t['#']='#'
        print(trie)
        row, col = len(board), 0
        if row > 0:
            col = len(board[0])
        self.v = [[False]*col for _ in range(row)]
        ret = set()
        for i in range(row):
            for j in range(col):
                self.dfs(board, row, col, i, j, trie, '', ret)
        return list(ret)
        
    def dfs(self,b,r,c, i, j,trie, word, ret):
        if '#' in trie:
            ret.add(word)
        if i<0 or i>=r or j<0 or j>=c or self.v[i][j]:
            return
        
        if b[i][j] in trie: #only one char can match trie each time
            self.v[i][j] = True
            self.dfs(b,r,c, i+1, j,trie[b[i][j]], word+b[i][j], ret)
            self.dfs(b,r,c, i, j+1,trie[b[i][j]], word+b[i][j], ret)
            self.dfs(b,r,c, i-1, j,trie[b[i][j]], word+b[i][j], ret)
            self.dfs(b,r,c, i, j-1,trie[b[i][j]], word+b[i][j], ret)
            self.v[i][j] = False
        
        
                
                    
                
            
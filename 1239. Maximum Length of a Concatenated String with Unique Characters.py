1239. Maximum Length of a Concatenated String with Unique Characters.py

# backtracking O(n!)
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        self.res = 0
        self.n = len(arr)
        def dfs(preStr, idx):
            if idx == self.n:
                return
            for i in range(idx, self.n):
                if len( set(preStr + arr[i]) ) == len( preStr ) + len( arr[i] ):
                    self.res = max(self.res, len(preStr + arr[i]))
                    dfs(preStr + arr[i], i+1)
        dfs("", 0)    
        return self.res


# dynamic programing O(2^n)
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        if len(arr) == 0:
            return 0
        curStr = arr[0]
        arrLeft = arr[1:]
        arrForCur = []
        if len(set(curStr)) != len(curStr):
            return self.maxLength(arrLeft)
        # collect element can concat to curStr
        for strForCur in arrLeft:
            if len( set(strForCur+curStr) ) == len(strForCur) + len(curStr): 
                arrForCur.append(strForCur)
        return max( self.maxLength(arrForCur)+len(curStr), self.maxLength(arrLeft) )
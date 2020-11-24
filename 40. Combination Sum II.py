40. Combination Sum II.py
class Solution(object):
    def dfs(self, cands, target, path, res):
        if target == 0:
            res.append(path)
            return
        if target < 0:
            return
        for i, cand in enumerate(cands):
            if cand > target:
                continue
            if i>0 and cands[i] == cands[i-1]:
                continue
            self.dfs(cands[i+1:], target-cand, path+[cand], res)
            
    def combinationSum2(self, candidates, target):
        candidates.sort()
        res = []
        self.dfs(candidates, target, [], res)
        return res
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
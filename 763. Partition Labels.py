# 763. Partition Labels.py
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        if len(S) <= 1:
            return [len(S)]
        # find left and right position of each character
        cs = {}
        for i, c in enumerate(S):
            if c in cs:
                cs[c][1] = i
            else:
                cs[c] = [i, i]
        
        # transfer dict to list in order the character first show up
        listC = []
        for c in S:
            if c in cs:
                listC.append(cs.pop(c))

        
        [curL, curR] = listC[0]
        idx = 1
        res = []
        while idx < len(listC):
            [L, R] = listC[idx]
            if L < curR and R > curR:
                curR = R
            if L > curR:
                res.append(curR - curL + 1)
                curL, curR = L, R
            idx += 1
        res.append(curR - curL + 1)
        return res
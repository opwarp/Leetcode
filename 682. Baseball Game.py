class Solution:
    def calPoints(self, ops: List[str]) -> int:
        valid = [0,0]
        res = 0
        for p in ops:
            if p == 'C':
                if len(valid) > 2:
                    res -= valid.pop()
            elif p == '+':
                valid.append(valid[-1] + valid[-2])
                res += valid[-1]
            elif p == 'D':
                valid.append(int(valid[-1]*2))
                res += valid[-1]
            else:
                valid.append(int(p))
                res += valid[-1]
        return res
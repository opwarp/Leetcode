# 38. Count and Say.py
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        cs = self.countAndSay(n-1)
        count = 0
        digit = cs[0]
        ret = ""
        for c in cs:
            if c != digit:
                ret += str(count)+digit
                digit = c
                count = 1
            else:
                count += 1
        ret += str(count)+digit
        return ret
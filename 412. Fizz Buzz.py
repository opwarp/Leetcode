# 412. Fizz Buzz.py
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []
        if n < 0:
            return []
        for i in range(1,n+1):
            nStr = ""
            if i % 3 != 0 and i % 5 != 0:
                nStr = str(i)
            if i % 3 == 0:
                nStr = "Fizz"
            if i % 5 == 0:
                nStr = nStr + "Buzz"
            res.append(nStr)
        return res
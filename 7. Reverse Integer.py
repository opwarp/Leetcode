# 7. Reverse Integer.py
class Solution:
    def reverse(self, x: int) -> int:
        maxInt = 2**31 - 1
        minInt = -2**31
        y = 0
        sign = [1,-1][x < 0]
        x = sign * x
        while x:
            digit = x % 10
            if (sign < 0 and digit > -minInt - y) or (sign > 0 and digit > maxInt - y):
                return 0
            if y > maxInt // 10:
                return 0
            x = x // 10
            y = y * 10 + digit
        return sign * y
        
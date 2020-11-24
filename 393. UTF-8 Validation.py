# 393. UTF-8 Validation.py

class Solution: # O(n)
    def validUtf8(self, data: List[int]) -> bool:
        count = 0
        for i in data:
            bi = format(i, '#010b')
            # print(bi)
            if count > 0:
                if bi[:4] != '0b10':
                    return False
                else:
                    count -= 1
            else:
                if bi[:3] == '0b0':
                    count = 0
                elif bi[:5] == '0b110':
                    count = 1
                elif bi[:6] == '0b1110':
                    count = 2
                elif bi[:7] == '0b11110':
                    count = 3
                else:
                    return False
            # print(count)
        return count == 0
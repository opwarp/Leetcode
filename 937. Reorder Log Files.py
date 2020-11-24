# 937. Reorder Log Files.py
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        num = []
        char = {}
        for i in logs:
            spl = i.split(' ')
            j = (' ').join(spl[1:]) + spl[0]
            if j[0] > '9':
                char[i] = j
            else:
                num.append(i)
                
        sortedChar = sorted(char, key = lambda x: char[x])
        return sortedChar + num
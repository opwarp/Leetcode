class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        last = [
            1, #[[1]], 
        ]
        for i in range(2, n+1):
            last = last + [0] * (i-1)
            current = [1]
            for j in range(1, len(last)):
                if j > k:
                    break
                if j >= i:
                    current.append(current[j-1] + last[j] - last[j-i])
                else:
                    current.append(current[j-1] + last[j])
                current[-1] = current[j] % (10 ** 9 + 7)
            last = current
            
        if len(last) > k:
            return last[k]
        else:
            return 0
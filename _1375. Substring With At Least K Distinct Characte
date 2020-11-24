_1375. Substring With At Least K Distinct Characters.py
class Solution:
    """
    @param s: a string
    @param k: an integer
    @return: the number of substrings there are that contain at least k distinct characters
    """
    def kDistinctCharacters(self, s, k):
        # Write your code here
        
        total = 0
        
        l, r = 0, 0
        for i in range(len(s)):
            r = i
            cDict = {}
            while r < len(s) and len(cDict) < k:
                if s[r] not in cDict:
                    cDict[s[r]] = 1
                else:
                    cDict[s[r]] += 1
                r+=1
       
            if len(cDict) >= k:
                total += (len(s)-r+1)
            
            l+=1
            
        return total
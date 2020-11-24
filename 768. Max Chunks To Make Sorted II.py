768. Max Chunks To Make Sorted II.py
# O(n^2)
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        if len(arr) == 0:
            return 0
        chunks = []
        for (i, num) in enumerate(arr):
            chunks.append({"begin":i,"max":num, "end":i}) # add single number as default chunk
            newChunks = [] # to load valid chunks
            for chunk in chunks:
                if num < chunk["max"]:
                    chunk["max"] = chunks[-2]["max"] # update chunk max with last chunk in last iteration
                    chunk["end"] = i # update chunk end
                    newChunks.append(chunk)
                    break # abandon follow chunks
                newChunks.append(chunk)
            chunks = newChunks
        # print(chunks)
        return len(chunks)
            
# O(n)
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        if len(arr) == 0:
            return 0
        minsRtoL = []
        arr.reverse()
        minRtoL = arr[0]
        for cur in arr:
            minRtoL = min(minRtoL, cur)
            minsRtoL.append( minRtoL )
        minsRtoL.reverse()
        arr.reverse()
        maxLtoR = arr[0]
        res = 1
        for (i, cur) in enumerate(arr[:-1]):
            maxLtoR = max(maxLtoR, cur)
            if maxLtoR <= minsRtoL[i+1]:#compare max from left to right with min from right to left in position i, if max < min, then chunk can be split here
                res += 1
        return res
# 692. Top K Frequent Words.py
class Element:
        def __init__(self, word, freq):
            self.word = word
            self.freq = freq
        def __lt__(self, other):
            if other.freq == self.freq:
                return other.word < self.word
            return other.freq > self.freq
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freq = {}
        for word in words:
            freq[word] = freq.get(word, 0) + 1
        wordFreqs = []
        for word in freq.keys():
            wordFreqs.append((word, freq[word]))
        
        heap = []
        # get ferquency first, then just need to maintain a k length sort
        for word, freq in wordFreqs:
            heapq.heappush(heap, Element(word, freq))
            if len(heap) > k:
                heapq.heappop(heap)
        result = []
        while len(heap) > 0:
            result.append(heapq.heappop(heap).word) #heap must pop to maintain order
        return result[::-1]
        
####################################

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freq = {}
        for word in words:
            freq[word] = freq.get(word, 0) + 1
        wordFreqs = []
        for word in freq.keys():
            wordFreqs.append((word, freq[word]))
        wordFreqs.sort(key=lambda elem:(-elem[1], elem[0]))
        return [word for word, freq in wordFreqs][:k]
        
        
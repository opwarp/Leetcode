# 127. Word Ladder.py
class Solution: #O(n*n)
    def stepWord(self, w1, w2):
        if len(w1) != len(w2):
            return False
        difNum = 0
        for i in range(len(w1)):
            if w1[i] != w2[i]:
                difNum +=1
        return difNum == 1
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wDict = collections.defaultdict(list)
        wStatu = {}
        for i in range(len(wordList)):
            if self.stepWord(wordList[i], beginWord):
                wDict[beginWord].append(wordList[i])
        for i in range(len(wordList)):
            wStatu[wordList[i]] = {'v': False, 'c': 0}
            for j in range(i+1, len(wordList)):
                if self.stepWord(wordList[i], wordList[j]):
                    wDict[wordList[i]].append(wordList[j])
                    wDict[wordList[j]].append(wordList[i])
        
        # print(wDict)
        #bfs
        dq = collections.deque()
        dq.append(beginWord)
        wStatu[beginWord] = {'v': True, 'c': 1}
        while dq:
            cur = dq.popleft()
            if cur == endWord:
                return wStatu[cur]['c']
            for w in wDict[cur]:
                if not wStatu[w]['v']:
                    wStatu[w]['v'] = True
                    wStatu[w]['c'] = wStatu[cur]['c'] + 1
                    dq.append(w)
                    
        return 0

#use set to find step word
class Solution: #O(wordlen*26*n)
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wSet = set(wordList)
        vSet = set([beginWord])
        #bfs
        dq = collections.deque()
        dq.append((beginWord, 1))
        while dq:
            cur, count = dq.popleft()
            if cur == endWord:
                return count
            for i in range(len(cur)):
                for cha in 'qwertyuiopasdfghjklzxcvbnm':
                    nxt = cur[:i] + cha + cur[i+1:]
                    if nxt in wSet and nxt not in vSet:
                        vSet.add(nxt)
                        dq.append((nxt, count+1))
                    
        return 0
# 126. Word Ladder II.py
class Solution:
    def __init__(self): #O(E*wlen*26)
        self.ret = []
        self.shortest = float('inf')
    def dfs(self, wCur, endWord, wSet, vSet, path):
        if len(path) > self.shortest:
            return
        if wCur == endWord:
            if len(path) <= self.shortest:
                self.shortest = len(path)
                self.ret.append(copy.copy(path))
            for i, p in enumerate(self.ret):
                if len(p) > self.shortest:
                    self.ret.pop(i)
            return
        for i in range(len(wCur)):
            for cha in 'qwertyuiopasdfghjklzxcvbnm':
                wNext = wCur[:i] + cha + wCur[i+1:]
                if wNext in wSet and wNext not in vSet:
                    # print(wCur)
                    # print(wNext)
                    vSet.add(wNext)
                    path.append(wNext)
                    self.dfs(wNext, endWord, wSet, vSet, path)
                    vSet.remove(wNext)
                    path.pop()
        return
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wSet = set(wordList)
        vSet = set([beginWord])
        path = [beginWord]
        self.dfs(beginWord, endWord, wSet, vSet, path)
        return self.ret

from collections import defaultdict
class Solution: # time O(wlen*n + E) space O(n)
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        #build dict
        mapNext = defaultdict(set)
        wordSet = set(wordList)
        graph = defaultdict(set)
        for word in wordList + [beginWord]:
            for i in range(len(word)):
                graph[word[:i] + '_' + word[i + 1:]].add(word)
        for word in wordList + [beginWord]:
            for i in range(len(word)):
                mapNext[word] = mapNext[word] | graph[word[:i] + '_' + word[i + 1:]] & wordSet
        queue = [[beginWord]]
        flag = False
        vSet = set([beginWord])
        #bfs
        while queue:
            new_queue = []
            to_remove = set()
            for path in queue:
                for new_word in mapNext[path[-1]]:
                    if new_word not in vSet:
                        new_queue.append(path + [new_word])
                        if new_word == endWord:
                            flag = True
                        else:
                            to_remove.add(new_word)
            if flag: return [p for p in new_queue if p[-1] == endWord]
            queue = new_queue[:]
            vSet = vSet | to_remove
        return []
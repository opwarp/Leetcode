# cheatSheet.py
#https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/discuss/289435/Python-DP
#2d list
dp = [[0 for j in xrange(len(s2) + 1)] for i in xrange(len(s1) + 1)]
#get char num
ord(s1[i - 1])
total = 0
for c in s1:
    total += ord(c)
#random list no duplicated
import random
random.sample(range(10), 10)
#findmiss
def findMiss(li):
    idx = len(li) // 2
    if li[idx] - li[idx-1] > 1:
        return li[idx] - 1
    res =  0
    if li[idx] == li[0] + idx:
        res = findMiss(li[idx:])
    else:
        res = findMiss(li[:idx])
    return res

#assemble
s = 0
c = a[0]
for i in a[1:]:
    c = c+i
    s = s+c
#default dict
cnt = collections.defaultdict(int)
#819
words = re.split(r'\W+', paragraph)
print(words)
# 1380.2
logsSorted.insert(i, log)
logsSortedC + logsSortedN
# 000 maze
import collections
dq = collections.deque()
dq.append({'x':1, 'y':1, 's':1})
pos = dq.popleft()
# 001 init array
buckets = [0] * 100
# 002 random
random.randint(-10,10) 
# list remove
a = [1,2,3,4]
a.remove(1)
# list index the first match element
a.index(3)
# smallest number
-float("inf")
# reverse range
range(5, 0, -1)
# set
vSet = set(['beginWord'])
wordSet = set(wordList)
mapNext[word] = mapNext[word] | graph[word[:i] + '_' + word[i + 1:]] & wordSet
mapNext[word] -= mapNext[word2]
# catch a spread list
a = []
a.append([1,2,3])
c,d,e = a.pop()
# set self.paramter in function
self.res=set()
# valid int
try:
    n = int(sec, 16)
except ValueError:
    return False
# check palindrome
s == s[::-1] 
# pickle and PATH
pickle.dump(vecd, open(PATH/f'wiki.{lang}.pkl','wb'))
# binary operator
sign = [1,-1][x < 0]
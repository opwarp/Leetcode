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
# format binary padding 0 
 format(14, '#010b')
 {}.format(14, '#010b')
#Fill the string with zeros until it is 10 characters long:
txt = "50"
x = txt.zfill(10)
# sort list
orgList
newList = sorted(orgList, key = lambda x: orgList[x])
# or
orgList.sort(orgList, key = lambda x: orgList[x])
# dict to list
l = list(dict.item())
# min heap: from min to max, maintain len 
import heapq
a = [3,2,1]
heapq.heapify(a)
# a become [1,2,3]
if len(heap) < 3:
    heapq.heappush(heap, num) # -num if max heap
else:
    heapq.heappushpop(heap, num)
# !!!!!!!! heappop to get ordered item
#The traditional solution is to store (priority, task) tuples on the heap:

pq = [ ]
heappush(pq, (10, task1))
heappush(pq, (5, task2))
heappush(pq, (15, task3))
priority, task = heappop(pq)


# defaultdict
from collections import defaultdict
dint1 = defaultdict(lambda: 0)
dint2 = defaultdict(int)
dlist1 = defaultdict(lambda: [])
dlist2 = defaultdict(list)

for ch in 'abracadabra':
    dint1[ch] += 1
    dint2[ch] += 1
    dlist1[ch].append(1)
    dlist2[ch].append(1)

# init 2d matrix
m = [[0]*3]*3 no!!!!!
t = [ [0]*3 for i in range(3)] #instead

# slice last n number
nums[-n:]
# slice first n number
nums[:n] #nums[0] ~ nums[n-1]
# slice middle n number
nums[i:j] #nums[i] ~ nums[j-1]
# bit transfer
# xor
# string count char
bin(x ^ y).count('1')
# Standard Python dictionaries are unordered. Even if you sorted the (key,value) pairs, you wouldn't be able to store them in a dict in a way that would preserve the ordering.

# The easiest way is to use OrderedDict, which remembers the order in which the elements have been inserted:

In [1]: import collections

In [2]: d = {2:3, 1:89, 4:5, 3:0}

In [3]: od = collections.OrderedDict(sorted(d.items()))

In [4]: od
Out[4]: OrderedDict([(1, 89), (2, 3), (3, 0), (4, 5)])
# Never mind the way od is printed out; it'll work as expected:

In [11]: od[1]
Out[11]: 89

In [12]: od[3]
Out[12]: 0

In [13]: for k, v in od.iteritems(): print k, v
   ....: 
1 89
2 3
3 0
4 5
Python 3
# For Python 3 users, one needs to use the .items() instead of .iteritems():

In [13]: for k, v in od.items(): print(k, v)
   ....: 
1 89
2 3
3 0
4 5
# meeting room.py
from heapq import heapify, heappop
intervals = [(0,30),(3,7),(10,20),(5,10),(15,20)]
print(intervals)
t = []
for i, itv in enumerate(intervals):
  print(itv)
  t.append([itv[0], i, 'bg'])
  t.append([itv[1], i, 'ed'])
heapify(t)
v = set()
count=0
while t:
  p = heappop(t)
  if p[2] == 'bg':
    v.add(p[1])
  if p[2] == 'ed' and p[1] in v:
    print(p[0])
    v = set()
    count+=1
print(count)


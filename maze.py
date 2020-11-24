maze = [
[0,0,0,0,0,0,0,0,0,0],
[0,1,1,0,1,1,1,0,0,0],
[0,1,1,0,1,1,1,0,1,0],
[0,1,1,1,1,0,0,1,1,0],
[0,1,0,0,0,1,1,1,1,0],
[0,1,1,1,0,1,0,1,1,0],
[0,1,0,1,1,1,0,1,1,0],
[0,1,0,0,0,1,0,1,1,0],
[0,0,1,1,1,1,1,1,1,0],
[0,0,0,0,0,0,0,0,0,0]
]

import collections
def bfs():
    dq = collections.deque()
    dq.append({'x':1, 'y':1, 's':1})
    while len(dq):
        pos = dq.popleft()
        if pos['x'] > len(maze) or pos['x'] < 0 or pos['y'] > len(maze[0]) or pos['y'] < 0 or maze[pos['x']][pos['y']] == 0 or maze[pos['x']][pos['y']] > 1:
            continue
        maze[pos['x']][pos['y']] = pos['s']
        if pos['x'] == 2 and pos['y'] == 8:
            return pos['s']
        dq.append({'x':pos['x']+1, 'y':pos['y'], 's':pos['s']+1})
        dq.append({'x':pos['x'], 'y':pos['y']+1, 's':pos['s']+1})
        dq.append({'x':pos['x']-1, 'y':pos['y'], 's':pos['s']+1})
        dq.append({'x':pos['x'], 'y':pos['y']-1, 's':pos['s']+1})
    return 0

print(bfs())
for i in range(10):
    print (maze[i])
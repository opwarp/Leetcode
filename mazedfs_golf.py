mazedfs_golf.py
maze = [
[0,0,0,0,0,0,0,0,0,0],
[0,1,1,0,3,1,1,0,0,0],
[0,1,1,0,1,1,2,0,1,0],
[0,1,1,1,1,0,0,1,1,0],
[0,1,0,0,0,1,1,1,1,0],
[0,1,1,1,0,1,0,1,1,0],
[0,1,0,1,1,1,0,1,1,0],
[0,1,0,0,0,1,0,1,1,0],
[0,0,1,1,1,1,1,1,1,0],
[0,0,0,0,0,0,0,0,0,0]
]

import collections

mrt = 9999

def dfs(r,c,mz,t,ed,rt):
    global mrt
    if mz[r][c] <= 0 or t < mz[r][c]:
        return
    
    if mz[r][c] == t:
        if t == ed:# meet end
            if rt < mrt:
                mrt = rt
#                 for i in mz:
#                     print (["{:0>2d}".format(j) for j in i])
#                 print (f'---------------------{mrt}')
        else:# meet tree
            t += 1
    tmp = mz[r][c]
    mz[r][c] = -1
    dfs(r+1,c,mz,t,ed,rt+1)
    dfs(r,c+1,mz,t,ed,rt+1)
    dfs(r-1,c,mz,t,ed,rt+1)
    dfs(r,c-1,mz,t,ed,rt+1)
    mz[r][c] = tmp

dfs(1,1,maze,2,3,0)
mrt
# for i in maze:
#     print (["{:0>2d}".format(j) for j in i])
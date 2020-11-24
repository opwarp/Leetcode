# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def solution(table):
    n = len(table)
    if n < 0:
        return 0
    m = len(table[0])
    i0, j0 = 0, 0
    res = 0
    for i in range(n):
        for j in range(m):
            if table[i][j] == 'O':
                i0, j0 = i, j
                table[i][j] == '.'
            
    def moveUR(i, j, c):
        movable = i >= 2 and j <= m-3
        if movable:
            beatable = table[i-1][j+1] == 'X' and table[i-2][j+2] == '.'
            if beatable:
                nonlocal res
                res = max(res, c+1)
                table[i-1][j+1] = '.'
                step(i-2, j+2, c+1)
                table[i-1][j+1] = 'X'
    
    def moveUL(i, j, c):
        movable = i >= 2 and j >= 2
        if movable:
            beatable = table[i-1][j-1] == 'X' and table[i-2][j-2] == '.'
            if beatable:
                nonlocal res
                res = max(res, c+1)
                table[i-1][j-1] = '.'
                step(i-2, j-2, c+1)
                table[i-1][j-1] = 'X'
            
    
    def step(i, j, c):
        moveUR(i, j, c)
        moveUL(i, j, c)
    step(i0, j0, 0)
    return res

table = [
    ['X','.','.','.','.','.'],
    ['.','X','.','.','.','.'],
    ['.','.','O','.','.','.'],
    ['.','.','.','X','.','.'],
    ['.','.','.','.','.','.']
    ]
  
print(solution(table))
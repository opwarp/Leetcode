## Maximal Minimum Value Path I

Given a two 2D integer array, find the max score of a path from the upper left cell to bottom right cell. The score of a path is the minimum value in that path.

**Notice**: the path can only right and down.

For example:

Input:

[7,5,3]
[2,0,9]
[4,5,9]

Here are some paths from [0,0] to [2,2] and the minimum value on each path:

path: 7->2->4->5->9, minimum value on this path: 2

path: 7->2->0->9->9, minimum value on this path: 0

path: 7->2->0->5->9, minimum value on this path: 0

In the end the max score(the min value) of all the paths is 3. 

Output: 3

```python
def maxPathScore(matrix):
    def dp(minScore, m, n):
        nonlocal matrix
        nonlocal matrixMinScore
        for i in range(m):
            for j in range(n):
                # if previous min Score is met,
                # change previous min Score to an inf number
                if matrix[i][j] == minScore:
                    matrix[i][j] = float('inf')
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    matrixMinScore[0][0] = matrix[0][0]
                else:
                    up = matrixMinScore[i-1][j] if i != 0 else float('inf')
                    left = matrixMinScore[i][j-1] if j != 0 else float('inf')
                    lastStep = min(up, left)
                    curStep = matrix[i][j]
                    if lastStep == float('inf') or curStep == float('inf'):
                        matrixMinScore[i][j] = float('inf')
                    else:
                        matrixMinScore[i][j] = min(lastStep, curStep)
        return matrixMinScore[m-1][n-1]
    m = len(matrix)
    if m == 0:
        return 0
    n = len(matrix[0])
    matrixMinScore = [[-1]*n for i in range(m)]
    curMinScore = -float('inf')
    res = curMinScore
    while True:
        curMinScore = dp(curMinScore, m, n)
        if curMinScore == float('inf'):
            break
        res = max(res, curMinScore)
    return res

```


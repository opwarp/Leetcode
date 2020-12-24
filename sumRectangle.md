```python
def calPix(pic, rects):
    m = len(pic)
    if m == 0:
        return 0
    n = len(pic[0])
    res = []
    # cal sum of pixel till each point
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                pass
            elif i == 0:
                pic[i][j] += pic[i][j-1]
            elif j == 0:
                pic[i][j] += pic[i-1][j]
            else:
                pic[i][j] += (pic[i-1][j]
                    + pic[i][j-1]
                    - pic[i-1][j-1])
    for rect in rects:
        top, left, botom, right = rect
        picTR = pic[top-1][right] if top > 0 else 0
        picBL = pic[botom][left-1] if left > 0 else 0
        picTL = pic[top-1][left-1] if top > 0 and left > 0 else 0
        rectSum = (pic[botom][right]
            - picTR
            - picBL
            + picTL)
        res.append(rectSum)
    return res
    
pic = [[0, 1, 2, 0], 

  [1, 3, 4, 2], 

  [3, 0, 4, 7], 

  [1, 1, 1, 5], 

  [3, 8, 2, 5]]

rects = [(1, 1, 2, 2), (0, 0, 1, 1), (2, 1, 3, 3)]

print(calPix(pic, rects))
```


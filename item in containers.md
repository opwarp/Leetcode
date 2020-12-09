<img src="item in containers.assets/image-20201207145746362.png" alt="image-20201207145746362" style="zoom:50%;" />

<img src="item in containers.assets/image-20201207145939003.png" alt="image-20201207145939003" style="zoom:50%;" />

<img src="item in containers.assets/image-20201207150041397.png" alt="image-20201207150041397" style="zoom:50%;" />

```python

              [|, *, *, *, |, *, *, |, *, |, *, *, |, *, *, *, *, *, *, *, |, *, *]
compIdxes     [0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5]
accumulates   [0, 1, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9, ...]
compaccus     [0, 3, 5, 6, 8, 15]
def solution(s, starts, ends): # O(n) time, O(n) space, n for max(len(s), len(starts))
    compAccms = []
    compIdxes = []
    curComp = -1
    accm = 0
    res = []
    for c in s:
        if c == '|':
            curComp += 1
            compAccms.append(accm)
            compIdxes.append([curComp, True])
        else:
            accm += 1
            compIdxes.append([curComp, False])
    for i in range(len(starts)):
        idx0, idx1 = starts[i]-1, ends[i]-1
        compIdx0, isEdge0 = compIdxes[idx0]
        compIdx1, _ = compIdxes[idx1]
        compIdx0 = compIdx0 if isEdge0 else compIdx0 + 1
        compIdx1 = compIdx1
        if compIdx0 < compIdx1:
            res.append(compAccms[compIdx1] - compAccms[compIdx0])
        else:
            res.append(0)
    print(compIdxes)
    print(compAccms)
    return res
print(solution(
        '|***|**|*|**|*******|**',
        [1,2,3,5],
        [9,4,8,23]
    ))
```
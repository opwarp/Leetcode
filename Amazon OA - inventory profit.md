<img src="Amazon OA - inventory profit.assets/image-20201220160433484.png" alt="image-20201220160433484" style="zoom:50%;" />

<img src="Amazon OA - inventory profit.assets/image-20201220160510406.png" alt="image-20201220160510406" style="zoom:50%;" />

<img src="Amazon OA - inventory profit.assets/image-20201220160801624.png" alt="image-20201220160801624" style="zoom:50%;" />

```python
def maxProfit(numSpplier, inventory, order):
    maxInv = max(inventory)
    listCountInv = [0] * (maxInv + 1)
    # count inventory that number ard the same
    for inv in inventory:
        listCountInv[inv] += 1
    idx = maxInv
    res = 0
    while idx > 0 and order > 0:
        # take the largest invertory
        if listCountInv[idx] > 0:
            res += idx
            listCountInv[idx] -= 1
            listCountInv[idx-1] += 1
            order -= 1
        else:
            # 0 count inventory
            idx -= 1
    return res

print(maxProfit(5, [2,8,4,6,10], 20))
```


## Amazon OA - Fill The Truck

An Amazon Warehouse manager needs to create a shipment to fill a truck. All of the products in the warehouse are in boxes of the same size. Each product is packed in some number of units per box.

Given the number of boxes the truck can hold, write an algorithm to determine the maximum number of units of any mix of products that can be shipped.

Input

The input to the function method consists of five arguments:

num, an integer representing number of products;

boxes, a list of integers representing the number of available boxes for products;

unitSize, an integer representing size of unitsPerBox;

unitsPerBox, a list of integers representing the number of units packed in each box;

truckSize, an integer representing the number of boxes the truck can carry.

Output

Return an integer representing the maximum units that can be carried by the truck.

Constraints

1 <= |boxes| <= 10^5

|boxes| == |unitsPerBox|

1 <= boxes[i] <= 10^7

1 <= i <= |boxes|

1 <= unitsParBox[i] <= 10^5

1 <= j <= |unitsPerBox|

1 <= truckSize <= 10 ^ 8

**Note**

[list name] denotes length of the list.

**Example**

Input:

num=3

boxes=[1,2,3]

unitSize=3

unitsPerBox= [3,2,1]

truckSize = 3

Output

7

Explanation:

Product 0: because boxes[0] = 1, we know there is 1 box in product 0. And because unitsPerBox[0] = 3, we know there is 1 box with 3 units in product 0.

Product 1: 2 boxes with 2 units each

Product 2: 3 boxes with 1 unit each

Finall we have the packed products like a list : [3, 2, 2, 1, 1, 1]

The truckSize is 3, so we pick the top 3 from the above list, which is [3, 2, 2], and return the sum 7.

The maximum number of units that can be shipped = 3 + 2 + 2 = 7 units



###### [More Amazon Online Assessment Questions 2020 Fall](https://aonecode.com/amazon-online-assessment-questions)

```python
def fillTheTruck(num: int, boxes: List[int], unitSize: int, unitsPerBox: List[int], truckSize: int) -> int:
    import heapq
    sortBoxes = []
    res = 0
    sumBox = 0
    for i in range(len(boxes)):
        boxNum, units = boxes[i], unitsPerBox[i]
        heapq.heappush(sortBoxes, (-units, boxNum))
    while len(sortBoxes) > 0:
        # get box with greatest unit
        units, boxNum = heapq.heappop(sortBoxes)
        needBoxNum = truckSize - sumBox
        if needBoxNum == 0:  # get enough boxes
            return res
        else:
            # add boxNum if need more boxes than boxNum
            addBoxNum = min(needBoxNum, boxNum)
            res -= units * addBoxNum
            sumBox += addBoxNum
    return res
```


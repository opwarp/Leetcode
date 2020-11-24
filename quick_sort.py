# quick_sort.py
def quick_sort(lists, left, right):
    '''快速排序'''
    # 跳出递归判断
    if left >= right:
        return lists
 
    # 选择参考点，该调整范围的第1个值
    key = lists[left]
    low = left  
    high = right
 
    # 循环判断直到遍历全部
    while left < right:
        # 从右边开始查找大于参考点的值
        while left < right and lists[right] >= key:
            right -= 1
        lists[left] = lists[right]  # 这个位置的值先挪到左边
 
        # 从左边开始查找小于参考点的值
        while left < right and lists[left] <= key:
            left += 1
        lists[right] = lists[left]  # 这个位置的值挪到右边
    
    
    # 写回改成的值
    lists[left] = key
    print(lists)
    # 递归，并返回结果
    quick_sort(lists, low, left - 1)    # 递归左边部分
    quick_sort(lists, left + 1, high)   # 递归右边部分
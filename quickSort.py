def quickSort(arr):
    if len(arr) <= 1:
        return arr
    idx = 0  # len(arr) // 2 # select target index
    targ = arr[idx]
    arrSw = arr[:idx] + arr[idx+1:]
    l, r = 0, len(arrSw) - 1
    brkPnt = 0
    # find a larger left and a smaller right, then switch
    while l < r:
        switL, switR = False, False
        if arrSw[l] > targ:
            switL = True
        else:
            l += 1
        if arrSw[r] < targ:
            switR = True
        else:
            r -= 1
        if switL and switR:
            arrSw[l], arrSw[r] = arrSw[r], arrSw[l]
            l += 1
            r -= 1
    # need to know arrSw[l] is larger or smaller
    if l == r:
        brkPnt = l + 1 if arrSw[l] < targ else l
    # switch happened the last iteration, arrSw[r] < target < arrSw[l]
    if l > r:
        brkPnt = l
    return quickSort(arrSw[:brkPnt]) + [targ] + quickSort(arrSw[brkPnt:])

print(quickSort([9, 3, 2, 5, 2, 1, 2, 3, 45, 4, 5, 6, 7, 8, 3, 66, 4]))

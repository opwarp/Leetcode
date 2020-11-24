# twosum_closest.py
a = [1,2,3,4,5,6,7,9] 

a.sort()
t = 12
l, r = 0, len(a)-1
ret = 99999
ret2  = []
while l<r:
    add = a[l]+a[r]
    if abs(t-add) < ret:
        ret = abs(t-add)
        ret2 = [l, r]
    if add > t:
        r-=1
    elif add < t:
        l+=1
    else:
        break
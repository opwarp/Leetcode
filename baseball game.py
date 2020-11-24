baseball game.py
def track_last_num(j):
    for i in range(j-1, 0, -1):
        if l[i] != "Z" and l[i] != "X" and l[i] != "+" and l[i] != "O":
            return int(l[i]), i
    return 0, 0
    
sum = 0
for i, n in enumerate(l):
    if n == "Z":
        m, k = track_last_num(i)
        l[k] = "O"
        sum -= m
    elif n== "X":
        m, k = track_last_num(i)
        l[i] = m*2
        sum += m*2
    elif n== "+":
        m, k = track_last_num(i)
        m2, k2 = track_last_num(k)
        l[i] = m+m2
        sum += (m+m2)
    else:
        sum += int(n)
    print(sum)
        
sum
print(l)
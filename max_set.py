sets = [{a[0][0],a[0][1]}]
for link in a[1:]:
    for s in sets:
        if link[0] in s:
            s.add(link[0])
            s.add(link[1])
            link = []
            break
        elif link[1] in s:
            s.add(link[0])
            s.add(link[1])
            link = []
            break
    if link != []:
        sets.append({link[0],link[1]})
        link = []
res = 0        
for i in sets:
    res = max(res, len(i) )
res
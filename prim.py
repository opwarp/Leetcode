# prim.py
from heapq import heapify, heappush, heappop
a = [[1, 4], [4, 5], [2, 3]]
b = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]

def prim(a, b):
    # build starts and ends
    roads = {}
    cities = set()
    for i in a:
        if i[0] not in roads:
            roads[i[0]] = [[ 0, i[1] ]]
        else:
            roads[i[0]].append([0, i[1]])
        if i[1] not in roads:
            roads[i[1]] = [[ 0, i[0] ]]
        else:
            roads[i[1]].append([0, i[0]])
    for i in b:
        if i[0] not in roads:
            roads[i[0]] = [[ i[2], i[1] ]]
        else:
            roads[i[0]].append([i[2], i[1]])
        if i[1] not in roads:
            roads[i[1]] = [[ i[2], i[0] ]]
        else:
            roads[i[1]].append([i[2], i[0]])
    for key in roads:
        cities.add(key)
        
    a = cities.pop()
    chosen = {a}
    cache = roads[a]
    heapify(cache)
    total = 0
    route = [str(a)]
    while cache:
        end = heappop(cache)
        if end[1] not in chosen:
            chosen.add(end[1])
            total += end[0]
            route.append(end[0])
            route.append(str(end[1]))
            for nextEnd in roads[end[1]]:
                if nextEnd[1] not in chosen:
                    heappush(cache, nextEnd)
    print(f'route{route}, total{total}')

prim(a, b)
# 218. The Skyline Problem.py
# O(nlog(n)) if use heap to maintain topBegins
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        points=[]
        res = []
        topBegins = []
        for (i, bar) in enumerate(buildings):
            begin, end, height = bar[0], bar[1], bar[2]
            if begin == end:
                if i == 0:
                    res.append([begin, 0])
                continue
            points.append([begin, height, 0])
            points.append([end, height, 1])
        points = sorted(points, key=lambda point:(point[0], point[2], -point[1]))
        
        # now go from left to right, when come across a begin point or end point, see if a contour point should be added or not.
        for point in points:
            [x, y, label] =  point
            if point[2] == 0: # come across begin point, higher than other ongoning  bar
                if topBegins == [] or topBegins[-1] < y:
                    res.append([x, y])
                # maintain topBegins in order form min to max
                if(topBegins == [] or y > topBegins[-1]):
                    topBegins.append(y)
                else:
                    for (i, topBegin) in enumerate(topBegins):
                        if y <= topBegin:
                            topBegins.insert(i, y)
                            break
            if point[2] == 1: 
                topBegins.remove(y)
                if topBegins == []: # come across end point, no other ongoing bar
                    if res[-1][0] == x:
                        res[-1][1] = 0
                    else:
                        res.append([x,0])
                elif topBegins[-1] < y and res[-1][0] != x: # come across end point, higher than other ongoning  bar, and no coinside
                    res.append([x,topBegins[-1]])
        return res
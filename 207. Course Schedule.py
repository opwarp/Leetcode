207. Course Schedule.py
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        cnt = collections.defaultdict(int)
        dep = collections.defaultdict(list)
        for i in prerequisites:
            dep[i[1]].append(i[0])
            cnt[i[0]] += 1
        
        # print(dep)
        # print(cnt[1])
        #bfs
        ret = []
        dq = collections.deque()
        for key in range(numCourses):
            if cnt[key] == 0:
                dq.append(key)
        while dq:
            dpcs = dq.popleft()
            ret.append(dpcs)
            if dpcs in dep:
                for cs in dep[dpcs]:
                    cnt[cs] -= 1
                    if cnt[cs] == 0:
                        dq.append(cs)
       
        return len(ret) == numCourses
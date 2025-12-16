class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        adjlist  = defaultdict(list)
        indegree= [0]*numCourses

        for course, preq in prerequisites:

            adjlist[preq].append(course)
            indegree[course]+=1


        q = deque([i for i in range(numCourses) if indegree[i] == 0])

        order = []

        while q:
            val = q.popleft()
            order.append(val)
            for lst in adjlist[val]:
                indegree[lst]-=1
                if indegree[lst] is 0:
                    q.append(lst)
    
        return True if len(order) == numCourses else False        
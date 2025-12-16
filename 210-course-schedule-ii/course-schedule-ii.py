class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # kahns algorihtm. 
        # firstly identify all the nodes which have indegree 0f 0. 

        
        adjlist = defaultdict(list)
        indegree = [0]*numCourses


        for course, preq in prerequisites:
            adjlist[preq].append(course)
            indegree[course]+=1
        
        q = deque([ i for i in range(numCourses) if indegree[i] == 0 ])

        order = []

        while q:
            val = q.popleft()
            order.append(val)
            
            for lst in adjlist[val]:

                indegree[lst]-=1
                if indegree[lst] is 0:
                    q.append(lst)


        return order if len(order) == numCourses else []

    
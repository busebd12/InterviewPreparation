from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph: list[int, list[int]]=[[] for iteration in range(0, numCourses)]

        indegree: list[int]=[0] * numCourses

        for prerequisite in prerequisites:
            a: int=prerequisite[0]

            b: int=prerequisite[1]

            graph[b].append(a)

            indegree[a]+=1

        queue: deque[int]=deque()

        for course in range(0, numCourses):
            if indegree[course]==0:
                queue.append(course)

        courses_taken: int=numCourses

        while queue:
            qSize: int=len(queue)

            for iteration in range(0, qSize):
                course: int=queue.popleft()

                courses_taken-=1

                for neighbour in graph[course]:
                    indegree[neighbour]-=1

                    if indegree[neighbour]==0:
                        queue.append(neighbour)

        return True if courses_taken==0 else False
import heapq

class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        result: int=0

        graph: List[List[int]]=[[] for iteration in range(0, n + 1)]

        indegree: List[int]=[0] * (n + 1)

        for relation in relations:
            previous_course: int=relation[0]

            next_course: int=relation[1]

            graph[previous_course].append(next_course)

            indegree[next_course]+=1

        queue: Deque[int]=deque()

        for node in range(1, n + 1):
            if indegree[node]==0:
                queue.append(node)

        courses_taken: int=0

        while queue:
            q_size: int=len(queue)

            for count in range(0, q_size):
                course: int=queue.popleft()

                courses_taken+=1

                for neighbour in graph[course]:
                    indegree[neighbour]-=1

                    if indegree[neighbour]==0:
                        queue.append(neighbour)
            result+=1

        if courses_taken < n:
            return -1

        return result
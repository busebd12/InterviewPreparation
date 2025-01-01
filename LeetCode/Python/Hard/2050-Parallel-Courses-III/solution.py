from collections import deque

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        result: int=0

        graph: List[List[int]]=self.build_graph(relations, n)

        indegree: List[int]=self.build_indegree_array(relations, n)

        queue: Deque[int]=deque()

        distances: List[int]=[0] * (n + 1)

        for course in range(1, n + 1):
            if not indegree[course]:
                distances[course]=time[course - 1]

                queue.append(course)

        while queue:
            q_size: int=len(queue)

            for iteration in range(0, q_size):
                course: int=queue.popleft()

                for next_course in graph[course]:
                    distances[next_course]=max(distances[next_course], distances[course] + time[next_course - 1])

                    indegree[next_course]-=1

                    if not indegree[next_course]:
                        queue.append(next_course)
        
        result=max(distances)
        
        return result
    
    def build_graph(self, relations: List[List[int]], n: int) -> List[List[int]]:
        graph: List[List[int]]=[[] for _ in range(0, n + 1)]

        for relation in relations:
            previous_course: int=relation[0]

            next_course: int=relation[1]

            graph[previous_course].append(next_course)

        return graph

    def build_indegree_array(self, relations: List[List[int]], n: int) -> List[int]:
        indegree: List[int]=[0] * (n + 1)

        for relation in relations:
            previous_course: int=relation[0]

            next_course: int=relation[1]

            indegree[next_course]+=1

        return indegree
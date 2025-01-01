from collections import deque

class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        result=0

        n=len(edges)

        graph=[[] for _ in range(0, n + 1)]

        for edge in edges:
            a=edge[0]

            b=edge[1]

            graph[a].append(b)

            graph[b].append(a)

        start=0

        path_length, first_farthest_node=self.bfs(graph, start)

        path_length, second_farthest_node=self.bfs(graph, first_farthest_node)

        return path_length

    def bfs(self, graph: List[List[int]], start: int) -> (int, int):
        queue=deque()

        visited=set()

        visited.add(start)

        queue.append(start)

        farthest_node_from_start=0

        level=0

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                node=queue.popleft()

                farthest_node_from_start=node

                for neighbour in graph[node]:
                    if neighbour not in visited:
                        queue.append(neighbour)

                        visited.add(neighbour)

            if queue:
                level+=1

        return (level, farthest_node_from_start)
from collections import deque

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        result=0

        if source==target:
            return result

        n=len(routes)

        graph=dict()

        for route in range(0, n):
            for stop in routes[route]:
                if stop not in graph.keys():
                    graph[stop]=list()

                graph[stop].append(route)

        if source not in graph.keys() or target not in graph.keys():
            return -1

        visited=[False for _ in range(0, n)]

        queue=deque()

        queue.append(source)

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                current_stop=queue.popleft()

                if current_stop==target:
                    return result

                for route in graph[current_stop]:
                    if visited[route]:
                        continue

                    visited[route]=True

                    for next_stop in routes[route]:
                        queue.append(next_stop)

            if queue:
                result+=1

        return -1
from collections import deque

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if not edges:
            return source==destination
        
        graph=[[] for _ in range(0, n)]

        for edge in edges:
            u=edge[0]

            v=edge[1]

            graph[u].append(v)

            graph[v].append(u)

        visited=set()

        return self.dfs(graph, visited, source, destination)

    def dfs(self, graph: List[List[int]], visited: Set[int], source: int, destination: int) -> bool:
        if source in visited:
            return False

        if source==destination:
            return True

        visited.add(source)

        for neighbour in graph[source]:
            if self.dfs(graph, visited, neighbour, destination):
                return True

        return False

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if not edges:
            return source==destination
        
        graph=[[] for _ in range(0, n)]

        for edge in edges:
            u=edge[0]

            v=edge[1]

            graph[u].append(v)

            graph[v].append(u)

        return self.dfs(graph, n, source, destination)

    def dfs(self, graph: List[List[int]], n: int, source: int, destination: int) -> bool:
        
        stack=list()
        
        visited=[False for _ in range(0, n)]

        visited[source]=True

        stack.append(source)

        while stack:
            node=stack.pop()

            if node==destination:
                return True

            for neighbour in graph[node]:
                if not visited[neighbour]:
                    visited[neighbour]=True

                    stack.append(neighbour)

        return False

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if not edges:
            return source==destination
        
        graph=[[] for _ in range(0, n)]

        for edge in edges:
            u=edge[0]

            v=edge[1]

            graph[u].append(v)

            graph[v].append(u)

        return self.bfs(graph, n, source, destination)

    def bfs(self, graph: List[List[int]], n: int, source: int, destination: int) -> bool:
        
        queue=deque()
        
        visited=[False for _ in range(0, n)]

        visited[source]=True

        queue.append(source)

        while queue:
            node=queue.popleft()

            if node==destination:
                return True

            for neighbour in graph[node]:
                if not visited[neighbour]:
                    visited[neighbour]=True

                    queue.append(neighbour)

        return False
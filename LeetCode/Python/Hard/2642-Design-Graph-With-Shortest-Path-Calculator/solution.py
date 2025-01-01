from collections import deque
import heapq

'''
Solution 1: Dijkstra's algorithm with minimum heap
'''
class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.N=n
        
        self.graph: List[List[Tuple[int, int]]]=self.build_graph(edges, n)

    def build_graph(self, edges: List[List[int]], n: int) -> List[List[Tuple[int, int]]]:
        graph: List[List[Tuple[int, int]]]=[[] for _ in range(0, n)]

        for edge in edges:
            u: int=edge[0]

            v: int=edge[1]

            weight: int=edge[2]

            graph[u].append((v, weight))

        return graph
        
    def addEdge(self, edge: List[int]) -> None:
        u: int=edge[0]

        v: int=edge[1]

        weight: int=edge[2]

        self.graph[u].append((v, weight))

    def shortestPath(self, node1: int, node2: int) -> int:
        min_heap: List[Tuple[int, int]]=list()

        INF: int=(2**53) - 1

        distances: List[int]=[INF for _ in range(0, self.N)]

        heapq.heappush(min_heap, (0, node1))

        distances[node1]=0

        while min_heap:
            current_weight, current_node=heapq.heappop(min_heap)

            for (neighbour, weight) in self.graph[current_node]:
                next_weight: int=current_weight + weight

                if next_weight < distances[neighbour]:
                    distances[neighbour]=next_weight

                    heapq.heappush(min_heap, (next_weight, neighbour))

        return -1 if distances[node2]==INF else distances[node2]

'''
Solution 2: Dijkstra's algorithm with (de)queue
'''
class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.N=n
        
        self.graph: List[List[Tuple[int, int]]]=self.build_graph(edges, n)

    def build_graph(self, edges: List[List[int]], n: int) -> List[List[Tuple[int, int]]]:
        graph: List[List[Tuple[int, int]]]=[[] for _ in range(0, n)]

        for edge in edges:
            u: int=edge[0]

            v: int=edge[1]

            weight: int=edge[2]

            graph[u].append((v, weight))

        return graph
        
    def addEdge(self, edge: List[int]) -> None:
        u: int=edge[0]

        v: int=edge[1]

        weight: int=edge[2]

        self.graph[u].append((v, weight))

    def shortestPath(self, node1: int, node2: int) -> int:
        queue: Deque[Tuple[int, int]]=deque()

        INF: int=(2**53) - 1

        distances: List[int]=[INF for _ in range(0, self.N)]

        queue.append((0, node1))

        distances[node1]=0

        while queue:
            nodes_in_current_level: int=len(queue)

            for iteration in range(0, nodes_in_current_level):
                current_weight, current_node=queue.popleft()

                for (neighbour, weight) in self.graph[current_node]:
                    next_weight: int=current_weight + weight

                    if next_weight < distances[neighbour]:
                        distances[neighbour]=next_weight

                        queue.append((next_weight, neighbour))

        return -1 if distances[node2]==INF else distances[node2]
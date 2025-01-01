import heapq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        result: int=0

        n: int=len(points)

        graph: List[List[Tuple[int, int]]]=[[] for iteration in range(0, n)]

        for i in range(0, n):
            for j in range(i + 1, n):
                point1: List[int]=points[i]

                point2: List[int]=points[j]

                manhattan_distance: int=self.get_manhattan_distance(point1, point2)

                graph[i].append((manhattan_distance, j))

                graph[j].append((manhattan_distance, i))

        min_heap: List[int]=list()

        visited: List[bool]=[False] * n

        heapq.heappush(min_heap, (0, 0))

        while min_heap:
            cost, index=heapq.heappop(min_heap)

            if visited[index]:
                continue

            visited[index]=True

            result+=cost

            for (manhattan_distance, neighbour) in graph[index]:
                heapq.heappush(min_heap, (manhattan_distance, neighbour))

        return result

    def get_manhattan_distance(self, point1: List[int], point2: List[int]) -> int:
        x1: int=point1[0]

        y1: int=point1[1]

        x2: int=point2[0]

        y2: int=point2[1]

        x_difference=abs(x1 - x2)

        y_difference=abs(y1 - y2)

        total: int=x_difference + y_difference

        return total
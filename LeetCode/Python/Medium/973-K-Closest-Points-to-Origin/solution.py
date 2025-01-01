import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        result=list()

        min_heap=list()

        for point in points:
            distance=self.get_distance(point)

            heapq.heappush(min_heap, (distance, point))

        while k > 0:
            distance, point=heapq.heappop(min_heap)

            result.append(point)

            k-=1

        return result

    def get_distance(self, point: List[int]) -> float:
        x1=0

        y1=0

        x2=point[0]

        y2=point[1]

        x_part=(x1 - x2)**2

        y_part=(y1 - y2)**2

        return math.sqrt(x_part + y_part)
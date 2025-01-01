import heapq
import math

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        result: int=0

        n: int=len(dist)

        min_heap: List[int]=list()

        for index in range(0, n):
            distance: int=dist[index]

            rate: int=speed[index]

            time_to_arrive: float=math.ceil(distance / rate)

            heapq.heappush(min_heap, time_to_arrive)

        minutes: int=0

        while min_heap:
            monster_arrival_time: int=heapq.heappop(min_heap)

            if minutes < monster_arrival_time:
                result+=1
            else:
                return result

            minutes+=1

        return result
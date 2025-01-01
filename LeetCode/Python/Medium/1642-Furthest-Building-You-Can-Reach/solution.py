class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        result=0

        n=len(heights)

        jumps=list()

        for index in range(1, n):
            difference=heights[index] - heights[index - 1]

            if difference > 0:
                bricks-=difference

                heapq.heappush(jumps, -difference)

                if bricks < 0:
                    if ladders==0:
                        return index - 1
                    else:
                        bricks-=heappop(jumps)

                        ladders-=1

        return n - 1
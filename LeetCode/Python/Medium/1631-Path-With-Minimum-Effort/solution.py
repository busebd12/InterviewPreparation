import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows: int=len(heights)

        columns: int=len(heights[0])

        infinity: int=pow(2, 53) - 1

        effort: List[List[int]]=[[infinity for iteration in range(0, columns)] for iteration in range(0, rows)]

        effort[0][0]=0

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        min_heap: List[Tuple[int, int, int]]=list()

        heapq.heappush(min_heap, (0, 0, 0))

        while min_heap:
            current_effort, row, column=heapq.heappop(min_heap)

            for (row_offset, column_offset) in directions:
                next_row: int=row + row_offset

                next_column: int=column + column_offset

                is_valid: bool=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                if is_valid:
                    height_difference: int=abs(heights[row][column] - heights[next_row][next_column])

                    next_effort: int=max(height_difference, current_effort)

                    if next_effort < effort[next_row][next_column]:
                        effort[next_row][next_column]=next_effort

                        heapq.heappush(min_heap, (next_effort, next_row, next_column))

        return effort[rows - 1][columns - 1]
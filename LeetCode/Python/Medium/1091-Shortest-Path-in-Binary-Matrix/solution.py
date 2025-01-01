from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        rows=len(grid)

        columns=len(grid[0])

        if grid[0][0]==1:
            return -1

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, 1), (1, -1), (-1, -1)]

        INF=(2**53) - 1

        distances=[[INF for _ in range(0, columns)] for _ in range(0, rows)]

        distances[0][0]=1

        queue=deque()

        queue.append((0, 0))

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                row, column=queue.popleft()

                for row_offset, column_offset in directions:
                    next_row=row + row_offset

                    next_column=column + column_offset

                    is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                    if is_valid and grid[next_row][next_column]==0:
                        if distances[row][column] + 1 < distances[next_row][next_column]:
                            distances[next_row][next_column]=distances[row][column] + 1

                            queue.append((next_row, next_column))

        return -1 if distances[rows - 1][columns - 1]==INF else distances[rows - 1][columns - 1]
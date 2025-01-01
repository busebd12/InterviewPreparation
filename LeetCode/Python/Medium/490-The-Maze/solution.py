from collections import deque

class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        rows: int=len(maze)

        columns: int=len(maze[0])

        visited: List[List[bool]]=[[False for iteration in range(0, columns)] for iteration in range(0, rows)]

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        queue: Deque[Tuple[int, int]]=deque()

        queue.append((start[0], start[1]))

        while queue:
            q_size: int=len(queue)

            for count in range(0, q_size):
                (row, column)=queue.popleft()

                if row==destination[0] and column==destination[1]:
                    return True

                for (row_offset, column_offset) in directions:
                    next_row: int=row

                    next_column: int=column
                    
                    while self.can_keep_rolling(maze, rows, columns, next_row + row_offset, next_column + column_offset):
                        next_row+=row_offset

                        next_column+=column_offset

                    if visited[next_row][next_column]==False:
                        visited[next_row][next_column]=True

                        queue.append((next_row, next_column))

        return False

    def can_keep_rolling(self, maze: List[List[int]], rows: int, columns: int, row: int, column: int) -> bool:
        invalid_row: bool=(row < 0 or row >= rows)

        invalid_column: bool=(column < 0 or column >= columns)

        if invalid_row or invalid_column:
            return False

        hit_a_wall: bool=(maze[row][column]==1)

        if hit_a_wall:
            return False

        return True
from collections import deque
import heapq

#Solution 1: Dijkstra's Algorithm
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        result: int=0

        rows: int=len(maze)

        columns: int=len(maze[0])

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        INF: int=(2**53) - 1

        distances: List[List[int]]=[[INF for _ in range(0, columns)] for _ in range(0, rows)]

        min_heap: List[List[int]]=list()

        distances[start[0]][start[1]]=0

        heapq.heappush(min_heap, [0, start[0], start[1]])

        while min_heap:
            state: List[int]=heapq.heappop(min_heap)

            distance: int=state[0]

            row: int=state[1]

            column: int=state[2]

            if row==destination[0] and column==destination[1]:
                return distance

            for (row_offset, column_offset) in directions:
                next_row: int=row

                next_column: int=column

                distance_rolled, row_stopped_at, column_stopped_at=self.get_distance_rolled(maze, rows, columns, next_row, next_column, row_offset, column_offset)

                next_distance: int=distances[row][column] + distance_rolled

                if next_distance < distances[row_stopped_at][column_stopped_at]:
                    distances[row_stopped_at][column_stopped_at]=next_distance

                    heapq.heappush(min_heap, [next_distance, row_stopped_at, column_stopped_at])

        return -1

    def get_distance_rolled(self, maze: List[List[int]], rows: int, columns: int, next_row: int, next_column: int, row_offset: int, column_offset: int) -> Tuple[int, int, int]:
        distance_rolled: int=0
        
        while self.can_keep_rolling(maze, rows, columns, next_row + row_offset, next_column + column_offset):
            distance_rolled+=1
            
            next_row+=row_offset

            next_column+=column_offset

        return (distance_rolled, next_row, next_column)

    def can_keep_rolling(self, maze: List[List[int]], rows: int, columns: int, next_row: int, next_column: int) -> bool:
        invalid_row: bool=((next_row < 0) or (next_row >= rows))

        invalid_column: bool=((next_column < 0) or (next_column >= columns))

        if invalid_row or invalid_column:
            return False

        hit_a_wall: bool=(maze[next_row][next_column]==1)

        if hit_a_wall:
            return False

        return True

#Solution 2: breadth-first search with 2D distances list
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        result: int=0

        rows: int=len(maze)

        columns: int=len(maze[0])

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        INF: int=(2**53) - 1

        distances: List[List[int]]=[[INF for _ in range(0, columns)] for _ in range(0, rows)]

        queue: Deque[List[int]]=deque()

        distances[start[0]][start[1]]=0

        queue.append([start[0], start[1]])

        while queue:
            q_size: int=len(queue)

            for count in range(0, q_size):
                state: List[int]=queue.popleft()

                row: int=state[0]

                column: int=state[1]

                for (row_offset, column_offset) in directions:
                    next_row: int=row

                    next_column: int=column

                    distance_rolled, row_stopped_at, column_stopped_at=self.get_distance_rolled(maze, rows, columns, next_row, next_column, row_offset, column_offset)

                    next_distance: int=distances[row][column] + distance_rolled

                    if next_distance < distances[row_stopped_at][column_stopped_at]:
                        distances[row_stopped_at][column_stopped_at]=next_distance

                        queue.append([row_stopped_at, column_stopped_at])

        return -1 if distances[destination[0]][destination[1]]==INF else distances[destination[0]][destination[1]]

    def get_distance_rolled(self, maze: List[List[int]], rows: int, columns: int, next_row: int, next_column: int, row_offset: int, column_offset: int) -> Tuple[int, int, int]:
        distance_rolled: int=0
        
        while self.can_keep_rolling(maze, rows, columns, next_row + row_offset, next_column + column_offset):
            distance_rolled+=1
            
            next_row+=row_offset

            next_column+=column_offset

        return (distance_rolled, next_row, next_column)

    def can_keep_rolling(self, maze: List[List[int]], rows: int, columns: int, next_row: int, next_column: int) -> bool:
        invalid_row: bool=((next_row < 0) or (next_row >= rows))

        invalid_column: bool=((next_column < 0) or (next_column >= columns))

        if invalid_row or invalid_column:
            return False

        hit_a_wall: bool=(maze[next_row][next_column]==1)

        if hit_a_wall:
            return False

        return True
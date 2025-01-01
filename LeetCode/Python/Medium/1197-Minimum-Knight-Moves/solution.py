from collections import deque

class Solution:
    def __init__(self):
        self.directions: List[Tuple[int, int]]=[(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)]

    def minKnightMoves(self, x: int, y: int) -> int:
        result: int=0

        visited: Set[Tuple[int, int]]=set()

        visited.add((0, 0))

        queue: Deque[Tuple[int, int]]=deque()

        queue.append((0, 0))

        while queue:
            nodes_in_current_level: int=len(queue)

            for iteration in range(0, nodes_in_current_level):
                row, column=queue.popleft()

                if row==x and column==y:
                    return result

                for (row_offset, column_offset) in self.directions:
                    next_row: int=row + row_offset

                    next_column: int=column + column_offset

                    if (next_row, next_column) not in visited:
                        visited.add((next_row, next_column))

                        queue.append((next_row, next_column))

            if queue:
                result+=1

        return -1
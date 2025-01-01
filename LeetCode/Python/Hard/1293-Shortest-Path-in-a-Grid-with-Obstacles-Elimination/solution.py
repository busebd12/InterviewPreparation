from collections import deque

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        seen_states=set()

        seen_states.add(str(0) + str(0) + str(k))

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        queue=deque()

        queue.append((0, 0, k))

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                row, column, obstacles_we_can_eliminate=queue.popleft()

                if row==rows-1 and column==columns-1:
                    return result

                for (row_offset, column_offset) in directions:
                    next_row=row + row_offset

                    next_column=column + column_offset

                    is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                    if is_valid:
                        remaining_obstacles_we_can_eliminate=obstacles_we_can_eliminate - grid[next_row][next_column]

                        if remaining_obstacles_we_can_eliminate >= 0:
                            next_state=str(next_row) + str(next_column) + str(remaining_obstacles_we_can_eliminate)

                            if next_state not in seen_states:
                                seen_states.add(next_state)

                                queue.append((next_row, next_column, remaining_obstacles_we_can_eliminate))

            if queue:
                result+=1

        return -1
from collections import deque

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        rows: int=len(image)

        columns: int=len(image[0])

        if image[sr][sc]==color:
            return image

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        original_color: int=image[sr][sc]

        image[sr][sc]=color

        queue: Deque[Tuple[int, int]]=deque([(sr, sc)])

        while queue:
            nodes_in_current_level: int=len(queue)

            for iteration in range(0, nodes_in_current_level):
                row, column=queue.popleft()

                for (row_offset, column_offset) in directions:
                    next_row: int=row + row_offset

                    next_column: int=column + column_offset

                    is_valid: bool=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                    if is_valid and image[next_row][next_column]==original_color:
                        image[next_row][next_column]=color

                        queue.append((next_row, next_column))

        return image
from collections import deque

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows: int=len(mat)

        columns: int=len(mat[0])

        queue: Deque[Tuple[int, int]]=deque()

        for row in range(0, rows):
            for column in range(0, columns):
                if mat[row][column]==0:
                    queue.append((row, column))

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        visited: List[List[int]]=[[False for iteration in range(0, columns)] for iteration in range(0, rows)]

        distance: int=0

        while queue:
            q_size: int=len(queue)

            for count in range(0, q_size):
                (row, column)=queue.popleft()

                if mat[row][column]==1:
                    mat[row][column]=distance

                for (row_offset, column_offset) in directions:
                    next_row: int=row + row_offset

                    next_column: int=column + column_offset

                    is_valid: bool=(next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns)

                    if is_valid and mat[next_row][next_column]==1 and visited[next_row][next_column]==False:
                        visited[next_row][next_column]=True

                        queue.append((next_row, next_column))
            
            if queue:
                distance+=1
        
        return mat

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows: int=len(mat)

        columns: int=len(mat[0])

        max_int: int=pow(2, 53) - 1

        queue: Deque[Tuple[int, int]]=deque()

        for row in range(0, rows):
            for column in range(0, columns):
                if mat[row][column]==0:
                    queue.append((row, column))
                else:
                    mat[row][column]=max_int

        directions: List[Tuple[int, int]]=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        distance: int=1

        while queue:
            q_size: int=len(queue)

            for count in range(0, q_size):
                (row, column)=queue.popleft()

                for (row_offset, column_offset) in directions:
                    next_row: int=row + row_offset

                    next_column: int=column + column_offset

                    is_valid: bool=(next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns)

                    if is_valid and distance < mat[next_row][next_column]:
                        mat[next_row][next_column]=distance

                        queue.append((next_row, next_column))
            
            if queue:
                distance+=1
        
        return mat
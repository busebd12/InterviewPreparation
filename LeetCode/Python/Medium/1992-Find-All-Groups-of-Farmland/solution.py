from collections import deque

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        result=list()

        rows=len(land)

        columns=len(land[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if land[row][column]==1:
                    coordinates=[row, column, row, column]

                    self.dfs(land, directions, coordinates, rows, columns, row, column)

                    result.append(coordinates)

        return result

    def dfs(self, land: List[List[int]], directions: List[Tuple[int, int]], coordinates: List[int], rows: int, columns: int, row: int, column: int) -> None:
        land[row][column]=2

        for (row_offset, column_offset) in directions:
            next_row=row + row_offset

            next_column=column + column_offset

            is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

            if is_valid and land[next_row][next_column]==1:
                coordinates[2]=max(coordinates[2], next_row)

                coordinates[3]=max(coordinates[3], next_column)

                self.dfs(land, directions, coordinates, rows, columns, next_row, next_column)

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        result=list()

        rows=len(land)

        columns=len(land[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if land[row][column]==1:
                    coordinates=[row, column, row, column]

                    self.dfs(land, directions, coordinates, rows, columns, row, column)

                    result.append(coordinates)

        return result

    def dfs(self, land: List[List[int]], directions: List[Tuple[int, int]], coordinates: List[int], rows: int, columns: int, row: int, column: int) -> None:
        stack=list()
        
        land[row][column]=2

        stack.append((row, column))

        while stack:
            current_row, current_column=stack.pop()
            
            for (row_offset, column_offset) in directions:
                next_row=current_row + row_offset

                next_column=current_column + column_offset

                is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                if is_valid and land[next_row][next_column]==1:
                    coordinates[2]=max(coordinates[2], next_row)

                    coordinates[3]=max(coordinates[3], next_column)

                    land[next_row][next_column]=2

                    stack.append((next_row, next_column))

class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        result=list()

        rows=len(land)

        columns=len(land[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if land[row][column]==1:
                    coordinates=[row, column, row, column]

                    self.bfs(land, directions, coordinates, rows, columns, row, column)

                    result.append(coordinates)

        return result

    def bfs(self, land: List[List[int]], directions: List[Tuple[int, int]], coordinates: List[int], rows: int, columns: int, row: int, column: int) -> None:
        queue=deque()
        
        land[row][column]=2

        queue.append((row, column))

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                current_row, current_column=queue.popleft()
                
                for (row_offset, column_offset) in directions:
                    next_row=current_row + row_offset

                    next_column=current_column + column_offset

                    is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                    if is_valid and land[next_row][next_column]==1:
                        coordinates[2]=max(coordinates[2], next_row)

                        coordinates[3]=max(coordinates[3], next_column)

                        land[next_row][next_column]=2

                        queue.append((next_row, next_column))
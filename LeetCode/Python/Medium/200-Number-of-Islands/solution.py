from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if grid[row][column]=='1':
                    self.dfs(grid, directions, rows, columns, row, column)

                    result+=1

        return result

    def dfs(self, grid: List[List[int]], directions: List[Tuple[int, int]], rows: int, columns: int, row: int, column: int) -> None:
        grid[row][column]='2'

        for (row_offset, column_offset) in directions:
            next_row=row + row_offset

            next_column=column + column_offset

            is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

            if is_valid and grid[next_row][next_column]=='1':
                self.dfs(grid, directions, rows, columns, next_row, next_column)

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if grid[row][column]=='1':
                    self.dfs(grid, directions, rows, columns, row, column)

                    result+=1

        return result

    def dfs(self, grid: List[List[int]], directions: List[Tuple[int, int]], rows: int, columns: int, row: int, column: int) -> None:
        stack=list()
        
        grid[row][column]='2'

        stack.append((row, column))

        while stack:
            current_row, current_column=stack.pop()
            
            for (row_offset, column_offset) in directions:
                next_row=current_row + row_offset

                next_column=current_column + column_offset

                is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                if is_valid and grid[next_row][next_column]=='1':
                    grid[next_row][next_column]='2'
                    
                    stack.append((next_row, next_column))

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result=0

        rows=len(grid)

        columns=len(grid[0])

        directions=[(-1, 0), (1, 0), (0, -1), (0, 1)]

        for row in range(0, rows):
            for column in range(0, columns):
                if grid[row][column]=='1':
                    self.dfs(grid, directions, rows, columns, row, column)

                    result+=1

        return result

    def dfs(self, grid: List[List[int]], directions: List[Tuple[int, int]], rows: int, columns: int, row: int, column: int) -> None:
        queue=deque()
        
        grid[row][column]='2'

        queue.append((row, column))

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                current_row, current_column=queue.popleft()
                
                for (row_offset, column_offset) in directions:
                    next_row=current_row + row_offset

                    next_column=current_column + column_offset

                    is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns))

                    if is_valid and grid[next_row][next_column]=='1':
                        grid[next_row][next_column]='2'
                        
                        queue.append((next_row, next_column))
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        result=None

        rows=len(grid)

        columns=len(grid[0])

        result=[[0 for _ in range(0, columns)] for _ in range(0, rows)]

        ones_rows_hashmap=self.create_rows_hashmap(grid, rows, columns, 1)

        ones_columns_hashmap=self.create_columns_hashmap(grid, rows, columns, 1)

        for row in range(0, rows):
            for column in range(0, columns):
                ones_in_row=ones_rows_hashmap[row]

                ones_in_column=ones_columns_hashmap[column]

                zeros_in_row=columns - ones_in_row

                zeros_in_column=rows - ones_in_column

                difference=ones_in_row + ones_in_column - zeros_in_row - zeros_in_column

                result[row][column]=difference

        return result

    def create_rows_hashmap(self, grid: List[List[int]], rows: int, columns: int, value: int) -> Dict[int, int]:
        rows_hashmap=[0 for _ in range(0, rows)]
        
        for row in range(0, rows):
            count=0

            for column in range(0, columns):
                if grid[row][column]==value:
                    count+=1

            rows_hashmap[row]=count

        return rows_hashmap

    def create_columns_hashmap(self, grid: List[List[int]], rows: int, columns: int, value: int) -> Dict[int, int]:
        columns_hashmap=[0 for _ in range(0, columns)]

        for column in range(0, columns):
            count=0

            for row in range(0, rows):
                if grid[row][column]==value:
                    count+=1

            columns_hashmap[column]=count
        
        return columns_hashmap
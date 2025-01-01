class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        result: int=0

        rows: int=len(grid)

        columns: int=len(grid[0])

        for row in range(0, rows):
            if grid[row][0] < 0:
                result+=columns
            else:
                first_negative_index: int=self.binary_search(grid[row], columns)

                if first_negative_index!=-1:
                    negatives=columns - first_negative_index
                    
                    result+=negatives

        return result

    def binary_search(self, row: List[int], columns: int) -> int:
        index: int=-1

        low: int=0

        high: int=columns - 1

        while low <= high:
            middle: int=(low + (high - low)//2)

            if row[middle] >= 0:
                low=middle + 1
            else:
                index=middle

                high=middle - 1
        return index
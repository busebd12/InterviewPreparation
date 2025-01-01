import math

class Solution:
    def __init__(self):
        self.directions=[(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, 1), (1, -1), (-1, -1)]

    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        result=None

        rows=len(img)

        columns=len(img[0])

        result=[[-1 for _ in range(0, columns)] for _ in range(0, rows)]

        for row in range(0, rows):
            for column in range(0, columns):
                average=self.get_average(img, rows, columns, row, column)

                result[row][column]=average

        return result

    def get_average(self, img: List[List[int]], rows: int, columns: int, row: int, column: int) -> int:
        total=img[row][column]

        neighbours=1

        for (row_offset, column_offset) in self.directions:
            neighbour_row=row + row_offset

            neighbour_column=column + column_offset

            valid_neighbour=((neighbour_row >= 0 and neighbour_row < rows) and (neighbour_column >= 0 and neighbour_column < columns))

            if valid_neighbour:
                total+=img[neighbour_row][neighbour_column]

                neighbours+=1

        average=math.floor(total / neighbours)

        return average
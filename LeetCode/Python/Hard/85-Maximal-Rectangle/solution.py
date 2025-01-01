class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        result=0

        rows=len(matrix)

        columns=len(matrix[0])

        heights=[0 for _ in range(0, columns)]

        for row in range(0, rows):
            self.update_heights(matrix, heights, columns, row)

            max_rectangle_area_in_histogram=self.get_max_rectangle_area_in_histogram(heights)

            result=max(result, max_rectangle_area_in_histogram)

        return result

    def update_heights(self, matrix: List[List[int]], heights: List[int], columns: int, row: int) -> None:
        for column in range(0, columns):
            if matrix[row][column]=='0':
                heights[column]=0
            else:
                heights[column]+=1

    def get_max_rectangle_area_in_histogram(self, heights: List[int]) -> int:
        max_area=0
        
        h=len(heights)

        staircase=list()

        for (index, step) in enumerate(heights):
            staircase_start_index=index
            
            if not staircase:
                staircase.append((staircase_start_index, step))
            else:
                if step < staircase[-1][1]:
                    while staircase and step < staircase[-1][1]:
                        (i, height)=staircase.pop()

                        width=index - i

                        area=height * width

                        max_area=max(max_area, area)

                        staircase_start_index=i

                    staircase.append((staircase_start_index, step))
                else:
                    staircase.append((staircase_start_index, step))

        while staircase:
            (index, height)=staircase.pop()

            width=h - index

            area=height * width

            max_area=max(max_area, area)

        return max_area
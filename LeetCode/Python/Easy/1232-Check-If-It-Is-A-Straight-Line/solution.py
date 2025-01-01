class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n: int=len(coordinates)

        if n <= 2:
            return True

        #Calculate the slope between the first two points
        previous_slope: int=self.get_slope(coordinates[0], coordinates[1])

        #Iterate from the third point through the rest of the points
        for index in range(2, n):
            #Calculate the slope betweeen the current point and the previous point
            current_slope=self.get_slope(coordinates[index - 1], coordinates[index])

            #If the current slope is not the same as the previous slope, then the points don't lie on the same line
            if current_slope!=previous_slope:
                return False

            previous_slope=current_slope

        return True

    def get_slope(self, first_point: list[int], second_point: list[int]) -> float:
        x1: int=first_point[0]

        y1: int=first_point[1]

        x2: int=second_point[0]

        y2: int=second_point[1]

        dx: int=x2 - x1

        dy: int=y2 - y1

        #If the denominator is zero, then dividing be zero would result in an undefined slope so just return infinity
        if dx==0:
            return float('inf')
        
        return (y2 - y1) / (x2 - x1)
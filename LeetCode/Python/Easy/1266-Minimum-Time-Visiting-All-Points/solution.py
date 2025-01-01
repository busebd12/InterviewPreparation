class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        result: int=0

        n: int=len(points)

        for index in range(0, n - 1):
            current_x, current_y=points[index]

            next_x, next_y=points[index + 1]

            x_difference: int=abs(current_x - next_x)

            y_difference: int=abs(current_y - next_y)

            result+=max(x_difference, y_difference)

        return result
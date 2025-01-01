class Solution:
    def trap(self, height: List[int]) -> int:
        result=0

        n=len(height)

        max_left_boundary=[0 for _ in range(0, n)]

        max_left_boundary[0]=height[0]

        for index in range(1, n):
            max_left_boundary[index]=max(height[index], max_left_boundary[index - 1])

        max_right_boundary=[0 for _ in range(0, n)]

        max_right_boundary[n - 1]=height[n - 1]

        for index in range(n - 2, -1, -1):
            max_right_boundary[index]=max(height[index], max_right_boundary[index + 1])

        for index in range(0, n):
            max_boundary_on_the_left=max_left_boundary[index]

            max_boundary_on_the_right=max_right_boundary[index]

            fill_line=min(max_boundary_on_the_left, max_boundary_on_the_right)

            water_trapped=fill_line - height[index]

            if water_trapped > 0:
                result+=water_trapped

        return result
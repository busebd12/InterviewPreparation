class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        result=list()

        n=len(heights)

        tallest_building_to_the_right=heights[n - 1]

        result.append(n-1)

        for index in range(n-2, -1, -1):
            if heights[index] > tallest_building_to_the_right:
                result.append(index)

            tallest_building_to_the_right=max(tallest_building_to_the_right, heights[index])
        
        result.sort()

        return result

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n=len(heights)

        stack=list()

        for index in range(0, n):
            while stack and heights[stack[-1]] <= heights[index]:
                stack.pop()

            stack.append(index)

        return stack
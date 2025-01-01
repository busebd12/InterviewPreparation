class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        result=0

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

                        result=max(result, area)

                        staircase_start_index=i

                    staircase.append((staircase_start_index, step))
                else:
                    staircase.append((staircase_start_index, step))

        while staircase:
            (index, height)=staircase.pop()

            width=h - index

            area=height * width

            result=max(result, area)

        return result
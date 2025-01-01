class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        result: int=0

        n: int=len(intervals)

        if n==1:
            return result

        intervals.sort(key=lambda interval: interval[1])

        previous_end=intervals[0][1]

        for index in range(1, n):
            current_start: int=intervals[index][0]
            
            current_end: int=intervals[index][1]

            if current_start < previous_end:
                result+=1
            else:
                previous_end=current_end

        return result
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result=list()

        if not intervals:
            result.append(newInterval)

            return result

        intermediate_intervals=list()

        new_interval_start=newInterval[0]

        new_interval_end=newInterval[1]

        overlaps=False

        for interval in intervals:
            interval_start=interval[0]

            interval_end=interval[1]

            if new_interval_end < interval_start or interval_end < new_interval_start:
                intermediate_intervals.append(interval)
            else:
                overlaps=True
                
                merged_interval=[min(interval_start, new_interval_start), max(interval_end, new_interval_end)]

                intermediate_intervals.append(merged_interval)

        if not overlaps:
            m=len(intermediate_intervals)
            
            insertion_index=-1

            for index in range(1, m):
                current_interval_start=intermediate_intervals[index][0]

                current_interval_end=intermediate_intervals[index][1]

                previous_interval_start=intermediate_intervals[index - 1][0]

                previous_interval_end=intermediate_intervals[index - 1][1]
                
                if previous_interval_end < new_interval_start and new_interval_end < current_interval_start:
                    insertion_index=index

                    break

            if insertion_index==-1:
                if new_interval_end < intermediate_intervals[0][0]:
                    insertion_index=0
                elif intermediate_intervals[m - 1][1] < new_interval_end:
                    insertion_index=m

            for index in range(0, m):
                if len(result)==insertion_index:
                    result.append(newInterval)

                result.append(intermediate_intervals[index])

                if len(result)==insertion_index:
                    result.append(newInterval)

            return result

        result.append(intermediate_intervals[0])

        for index in range(1, len(intermediate_intervals)):
            current_interval_start=intermediate_intervals[index][0]

            current_interval_end=intermediate_intervals[index][1]

            result_interval_start=result[-1][0]

            result_interval_end=result[-1][1]

            if current_interval_end < result_interval_start or result_interval_end < current_interval_start:
                result.append([current_interval_start, current_interval_end])
            else:
                merged_interval=[min(result_interval_start, current_interval_start), max(result_interval_end, current_interval_end)]

                result.pop()
                
                result.append(merged_interval)

        return result
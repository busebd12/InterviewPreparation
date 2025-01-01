class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        result=list()

        to_be_removed_start=toBeRemoved[0]

        to_be_removed_end=toBeRemoved[1]

        for interval in intervals:
            current_interval_start=interval[0]

            current_interval_end=interval[1]

            if (to_be_removed_start < current_interval_start and to_be_removed_end < current_interval_start) or (to_be_removed_start > current_interval_end and to_be_removed_end > current_interval_end):
                result.append(interval)
            elif to_be_removed_start <= current_interval_start and to_be_removed_end >= current_interval_end:
                continue
            elif (current_interval_start < to_be_removed_start and to_be_removed_start < current_interval_end) and (current_interval_start < to_be_removed_end and to_be_removed_end < current_interval_end):
                result.append([current_interval_start, to_be_removed_start])

                result.append([to_be_removed_end, current_interval_end])
            elif (to_be_removed_start <= current_interval_start) and (current_interval_start <= to_be_removed_end and to_be_removed_end < current_interval_end):
                result.append([max(current_interval_start, to_be_removed_end), current_interval_end])
            elif (to_be_removed_end >= current_interval_end) and (current_interval_start < to_be_removed_start and to_be_removed_start <= current_interval_end):
                result.append([current_interval_start, min(current_interval_end, to_be_removed_start)])

        return result
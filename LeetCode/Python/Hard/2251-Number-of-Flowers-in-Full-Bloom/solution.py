class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        result: List[int]=list()

        f: int=len(flowers)

        p: int=len(people)

        start_times: List[int]=[-1] * f

        end_times: List[int]=[-1] * f

        for index in range(0, f):
            start_time: int=flowers[index][0]

            end_time: int=flowers[index][1]

            start_times[index]=start_time

            end_times[index]=end_time

        start_times.sort()

        end_times.sort()

        for index in range(0, p):
            time: int=people[index]

            latest_flower_already_blooming_index: int=self.get_upper_bound(start_times, f, time)

            flowers_already_blooming: int=latest_flower_already_blooming_index + 1

            latest_flower_stopped_blooming_index: int=self.get_lower_bound(end_times, f, time)

            flowers_stopped_blooming: int=latest_flower_stopped_blooming_index + 1

            flowers_in_full_bloom: int=flowers_already_blooming - flowers_stopped_blooming

            result.append(flowers_in_full_bloom)

        return result

    def get_upper_bound(self, start_times: List[int], f: int, time: int) -> int:
        index: int=-1

        low: int=0

        high: int=f - 1

        while low <= high:
            middle: int=low + ((high - low) // 2)

            if start_times[middle] <= time:
                index=middle

                low=middle + 1
            else:
                high=middle - 1

        return index

    def get_lower_bound(self, end_times: List[int], f: int, time: int) -> int:
        index: int=-1

        low: int=0

        high: int=f - 1

        while low <= high:
            middle: int=low + ((high - low) // 2)

            if end_times[middle] < time:
                index=middle

                low=middle + 1
            else:
                high=middle - 1

        return index
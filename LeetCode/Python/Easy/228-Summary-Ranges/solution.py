class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result: list[str]=list()

        n: int=len(nums)

        if n==0:
            return result

        separator: str='->'

        range_start: int=nums[0]

        index: int=0

        while index < n:
            j: int=index + 1

            while j < n and nums[j] - 1 == nums[j - 1]:
                j+=1

            range_end: int=nums[j - 1]

            summary: str=""

            if range_start!=range_end:
                summary=separator.join((str(range_start), str(range_end)))
            else:
                summary=str(range_start)

            result.append(summary)

            if j < n:
                range_start=nums[j]

            index=j

        return result
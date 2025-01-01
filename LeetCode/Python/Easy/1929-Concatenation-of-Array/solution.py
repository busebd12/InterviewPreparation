class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        result: List[int]=list()

        n: int=len(nums)

        for iteration in range(0, 2):
            for index in range(0, n):
                result.append(nums[index])

        return result
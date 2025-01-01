class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n: int=len(nums)

        result: List[int]=[0] * n

        result[0]=nums[0]

        for index in range(1, n):
            result[index]=result[index - 1] + nums[index]

        return result
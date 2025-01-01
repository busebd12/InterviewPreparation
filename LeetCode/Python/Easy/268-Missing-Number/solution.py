class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n: int=len(nums)

        total: int=sum(number for number in range(0, n + 1))

        for number in nums:
            total-=number

        return total
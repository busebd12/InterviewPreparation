class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if not self.is_monotonic_increasing(nums) and not self.is_monotonic_decreasing(nums):
            return False

        return True

    def is_monotonic_increasing(self, nums: List[int]) -> bool:
        n: int=len(nums)

        for index in range(1, n):
            if nums[index] > nums[index - 1]:
                return False

        return True

    def is_monotonic_decreasing(self, nums: List[int]) -> bool:
        n: int=len(nums)

        for index in range(1, n):
            if nums[index] < nums[index - 1]:
                return False

        return True
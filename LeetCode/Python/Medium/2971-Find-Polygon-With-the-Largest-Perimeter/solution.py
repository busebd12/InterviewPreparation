class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        result=-1

        n=len(nums)

        nums.sort()

        prefix_sums=[0 for _ in range(0, n)]

        prefix_sums[0]=nums[0]

        for index in range(1, n):
            prefix_sums[index]=nums[index] + prefix_sums[index - 1]

        for index in range(2, n):
            largest_side=prefix_sums[index] - prefix_sums[index - 1]

            sum_of_remaining_sides=prefix_sums[index - 1]

            if largest_side < sum_of_remaining_sides:
                result=max(result, prefix_sums[index])

        return result
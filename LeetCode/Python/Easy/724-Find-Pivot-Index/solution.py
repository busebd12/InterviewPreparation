class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n: int=len(nums)

        prefix_sums: List[int]=self.get_prefix_sums(nums, n)

        suffix_sums: List[int]=self.get_suffix_sums(nums, n)

        for index in range(0, n):
            left_sum: int=0
            
            if index - 1 >= 0:
                left_sum=prefix_sums[index - 1]

            right_sum: int=0
            
            if index + 1 < n:
                right_sum=suffix_sums[index + 1]

            if left_sum==right_sum:
                return index

        return -1

    def get_prefix_sums(self, nums: List[int], n: int) -> List[int]:
        prefix_sums: List[int]=[0 for _ in range(0, n)]

        prefix_sums[0]=nums[0]

        for index in range(1, n):
            prefix_sums[index]=prefix_sums[index - 1] + nums[index]

        return prefix_sums

    def get_suffix_sums(self, nums: List[int], n: int) -> List[int]:
        suffix_sums: List[int]=[0 for _ in range(0, n)]

        suffix_sums[n - 1]=nums[n - 1]

        for index in range(n - 2, -1, -1):
            suffix_sums[index]=suffix_sums[index + 1] + nums[index]

        return suffix_sums
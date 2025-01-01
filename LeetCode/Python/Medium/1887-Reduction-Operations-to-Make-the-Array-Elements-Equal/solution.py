class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        max_value: int=max(nums)

        frequencies: List[int]=[0 for _ in range(0, max_value + 1)]

        for number in nums:
            frequencies[number]+=1

        nums.sort()

        largest_index: int=n - 1

        next_largest_index: int=n - 2

        while next_largest_index >= 0:
            largest: int=nums[largest_index]

            next_largest: int=nums[next_largest_index]

            if largest > next_largest:
                largest_frequency: int=frequencies[largest]

                frequencies[next_largest]+=largest_frequency

                result+=largest_frequency

            largest_index-=1

            next_largest_index-=1

        return result
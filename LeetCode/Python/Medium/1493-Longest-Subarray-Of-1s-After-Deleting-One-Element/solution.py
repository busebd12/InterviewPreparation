class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        ones: int=sum(1 for number in nums if number==1)

        if ones==n:
            result=ones - 1

            return result

        zeros: int=sum(0 for number in nums if number==0)

        if zeros==n:
            return result

        zero_indices: list[int]=list()

        for index in range(0, n):
            if nums[index]==0:
                zero_indices.append(index)

        for index in zero_indices:
            ones_to_the_left: int=self.get_ones_to_the_left(nums, n, index)

            ones_to_the_right: int=self.get_ones_to_the_right(nums, n, index)

            total_ones: int=ones_to_the_left + ones_to_the_right

            result=max(result, total_ones)
        
        return result

    def get_ones_to_the_left(self, nums: list[int], n: int, index: int) -> int:
        ones_to_the_left: int=0

        left: int=index - 1

        while left >= 0 and nums[left]==1:
            ones_to_the_left+=1
            
            left-=1

        return ones_to_the_left

    def get_ones_to_the_right(self, nums: list[int], n: int, index: int) -> int:
        ones_to_the_right: int=0

        right: int=index + 1

        while right < n and nums[right]==1:
            ones_to_the_right+=1

            right+=1
        
        return ones_to_the_right
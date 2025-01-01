class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        limit: int=pow(2, 53) - 1
        
        result: int=limit

        n: int=len(nums)

        running_sum: int=0

        left: int=0

        right: int=0

        while right < n:
            while right < n and running_sum < target:
                running_sum+=nums[right]

                right+=1

            while left < right and running_sum >= target:
                length: int=right - left

                result=min(result, length)

                running_sum-=nums[left]

                left+=1

            if left==right:
                right+=1

        return result if result!=limit else 0
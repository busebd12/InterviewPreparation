class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        result: int=0

        n: int=len(nums)

        total: int=sum(nums)

        target_subarray_sum: int=total - x

        if target_subarray_sum==0:
            result=n

            return result

        left: int=0

        right: int=0

        sliding_window_sum: int=0

        subarray_length: int=0

        while right < n:
            sliding_window_sum+=nums[right]

            while left < right and sliding_window_sum > target_subarray_sum:
                sliding_window_sum-=nums[left]

                left+=1

            if sliding_window_sum==target_subarray_sum:
                length: int=(right - left) + 1

                subarray_length: int=max(subarray_length, length)

            right+=1
        
        if subarray_length==0:
            return -1

        result=n - subarray_length

        return result
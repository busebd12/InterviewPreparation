class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        result: int=0

        n: int=len(nums)
        
        subarray_length: int=1

        current_minimum: int=nums[k]

        result=current_minimum * subarray_length

        left: int=k - 1

        right: int=k + 1

        while left >= 0 or right < n:
            if left >= 0 and right < n:
                if nums[left] >= nums[right]:
                    current_minimum=min(current_minimum, nums[left])

                    left-=1
                else:
                    current_minimum=min(current_minimum, nums[right])

                    right+=1
            elif left < 0 and right < n:
                current_minimum=min(current_minimum, nums[right])

                right+=1
            else:
                current_minimum=min(current_minimum, nums[left])

                left-=1

            subarray_length+=1
            
            score: int=current_minimum * subarray_length

            result=max(result, score)

        return result
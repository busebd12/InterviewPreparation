class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        result=0

        if not nums:
            return result

        n=len(nums)

        if n < 3:
            return result

        nums.sort()

        for index in range(0, n-2):
            desired_sum=target - nums[index]

            left=index + 1

            right=n - 1

            while left < right:
                current_sum=nums[left] + nums[right]

                if current_sum < desired_sum:
                    pairs=right - left
                    
                    result+=pairs

                    left+=1
                else:
                    right-=1

        return result
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()

        n=len(nums)
        
        first=nums[n-1] * nums[n-2]
        
        second=nums[0] * nums[1]
        
        return first - second
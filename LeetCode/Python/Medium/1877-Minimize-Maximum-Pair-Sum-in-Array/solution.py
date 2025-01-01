class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        result: int=-1
            
        n: int=len(nums)
            
        nums.sort()
        
        left: int=0
            
        right: int=n - 1
        
        while left < right:
            pair_sum: int=nums[left] + nums[right]
                
            result=max(result, pair_sum)
            
            left+=1
            
            right-=1
            
        return result
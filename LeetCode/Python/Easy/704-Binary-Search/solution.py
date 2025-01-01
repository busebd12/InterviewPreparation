class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n: int=len(nums)

        low: int=0

        high: int=n-1

        while low <= high:
            middle: int=(low + (high - low)//2)

            if nums[middle]==target:
                return middle
            elif nums[middle] > target:
                high=middle - 1
            else:
                low=middle + 1
        
        return -1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n: int=len(nums)

        low: int=0

        high: int=n-1

        while low < high:
            middle: int=(low + (high - low)//2)

            if nums[middle]==target:
                return middle
            elif nums[middle] > target:
                high=middle
            else:
                low=middle + 1
        
        return low if nums[low]==target else -1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n: int=len(nums)
        
        index: int=bisect_left(nums, target)

        return index if index < n and nums[index]==target else -1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n: int=len(nums)
        
        index: int=bisect_right(nums, target)

        return index - 1 if nums[index - 1]==target else -1
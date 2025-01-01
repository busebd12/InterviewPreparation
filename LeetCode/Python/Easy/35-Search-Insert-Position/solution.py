class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
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

        return low + 1 if nums[low] < target else low

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        result: int=bisect_left(nums, target)

        return result

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        result: int=bisect_right(nums, target)

        return result - 1 if nums[result - 1]==target else result
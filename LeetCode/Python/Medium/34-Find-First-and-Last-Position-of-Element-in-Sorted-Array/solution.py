class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result: List[int]=[-1] * 2

        lower_bound: int=self.get_lower_bound(nums, target)

        if lower_bound!=-1:
            result[0]=lower_bound

        upper_bound: int=self.get_upper_bound(nums, target)

        if upper_bound!=-1:
            result[1]=upper_bound

        return result

    def get_lower_bound(self, nums: List[int], target: int) -> int:
        n: int=len(nums)

        lower_bound: int=-1

        low: int=0

        high: int=n-1

        while low <= high:
            middle: int=low + ((high - low) // 2)

            if nums[middle] >= target:
                if nums[middle]==target:
                    lower_bound=middle

                high=middle - 1
            else:
                low=middle + 1

        return lower_bound

    def get_upper_bound(self, nums: List[int], target: int) -> int:
        n: int=len(nums)

        upper_bound: int=-1

        low: int=0

        high: int=n-1

        while low <= high:
            middle: int=low + ((high - low) // 2)

            if nums[middle] <= target:
                if nums[middle]==target:
                    upper_bound=middle

                low=middle + 1
            else:
                high=middle - 1

        return upper_bound
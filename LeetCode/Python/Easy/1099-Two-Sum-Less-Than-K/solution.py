class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        result: int=-1

        n: int=len(nums)

        nums.sort()

        low: int=0

        high: int=n - 1

        while high > 0 and nums[high] >= k:
            high-=1

        while low < high:
            left: int=low

            while left < high and nums[left] + nums[high] < k:
                total: int=nums[left] + nums[high]

                result=max(result, total)

                left+=1

            high-=1

        return result

class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        result: int=-1

        n: int=len(nums)

        nums.sort()

        for index in range(n-1, -1, -1):
            first: int=nums[index]

            low: int=0

            high: int=index - 1

            total: int=self.binary_search(nums, k, first, low, high)

            if total!=-1:
                result=max(result, total)

        return result

    def binary_search(self, nums: List[int], k: int, first: int, low: int, high: int) -> int:
        total: int=-1

        while low <= high:
            middle: int=(low + (high - low) // 2)

            current_total: int=first + nums[middle]

            if current_total >= k:
                high=middle - 1
            else:
                total=current_total

                low=middle + 1

        return total
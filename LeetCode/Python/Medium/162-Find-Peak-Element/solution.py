class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n=len(nums)

        if n==1:
            return 0

        low=0

        high=n-1

        while low <= high:
            middle=(low + (high - low)//2)

            if middle-1 >= 0 and middle+1 < n:
                if nums[middle - 1] < nums[middle] and nums[middle] > nums[middle + 1]:
                    return middle
                else:
                    if nums[middle - 1] > nums[middle]:
                        high=middle - 1
                    elif nums[middle] < nums[middle + 1]:
                        low=middle + 1
            elif middle==0:
                if nums[middle] > nums[middle + 1]:
                    return middle
                else:
                    low=middle + 1
            else:
                if nums[middle] > nums[middle - 1]:
                    return middle
                else:
                    high=middle - 1

        return -1
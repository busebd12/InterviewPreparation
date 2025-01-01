#Inspired by this solution: https://leetcode.com/problems/missing-element-in-sorted-array/solutions/759881/python-more-in-depth-binary-search/
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        result: int=0

        n: int=len(nums)

        low: int=0

        high: int=n - 1

        missing_between_current_and_start=lambda index: nums[index] - nums[0] - index

        total_missing_numbers: int=missing_between_current_and_start(high)

        #If the total missing numbers between the first and last number in the array is less than k,
        #then the kth missing number won't be found between any two numbers in the arrayand it will only come after the last number in the array
        #Note: we subtract total_mising_numbers from k because we have to count all the missing numbers
        #that come before the kth one that are found between nums[0] and nums[-1]
        if k > total_missing_numbers:
            return nums[-1] + k - total_missing_numbers

        #Note the different while loop condition than normal binary search
        #It means we keep doing binary search until low and high mark a subarray of size=2
        #Once we shrink the search space down to a subarray of size=2, our answer will between those two numbers, nums[low] and nums[high]
        while (high - low) > 1:
            middle: int=(low + (high - low)//2)

            missing: int=missing_between_current_and_start(middle)

            #Also, note that we don't use middle - 1 or middle + 1 when deciding how to adjust low or high
            #This is because middle could still be the index of our answer, so we don't want to exclude it
            if missing >= k:
                high=middle
            else:
                low=middle

        #At this point, low and high form a subarray of size=2 and the kth missing number will be found between nums[low] and nums[high]
        result=nums[low] + k - missing_between_current_and_start(low)

        return result
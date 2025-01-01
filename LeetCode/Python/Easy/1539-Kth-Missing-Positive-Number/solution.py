class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        n: int=len(arr)

        low: int=0

        high: int=n - 1

        while low <= high:
            middle: int=(low + (high - low)//2)

            #Calculate the amount of missing numbers between 1 and arr[middle] inclusive
            missing: int=self.get_missing_numbers(arr, middle)

            #If the amount of missing numbers is greater than or equal to k, then the kth missing positive number exists between arr[low] and arr[middle - 1]
            if missing >= k:
                high=middle - 1
            #Else, the kth missing number exists between arr[middle + 1] and arr[high]
            else:
                low=middle + 1
        
        #Calculate the amount of missing numbers between 1 and arr[high] inclusive
        missing: int=self.get_missing_numbers(arr, high)

        #The kth missing number will be found (k - missing) numbers after arr[high]
        #We subtract missing from k to account for the amount of missing numbers that occur before arr[high]
        #The remaining amount of missing numbers will be added to arr[high] to get the answer 
        return arr[high] + (k - missing)

    def get_missing_numbers(self, nums: List[int], index: int) -> int:
        return nums[index] - index - 1
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        result: int=-1

        n: int=len(arr)

        low: int=0

        high: int=n - 1

        while low <= high:
            middle: int=(low + (high - low)//2)

            if 0 < middle and middle < n-1:
                if arr[middle - 1] < arr[middle] and arr[middle] > arr[middle + 1]:
                    result=middle

                    return result
                elif arr[middle - 1] < arr[middle] and arr[middle] < arr[middle + 1]:
                    low=middle + 1
                elif arr[middle - 1] > arr[middle] and arr[middle] > arr[middle + 1]:
                    high=middle - 1
            elif middle==0:
                low=middle + 1
            else:
                high=middle + 1
        
        return result
class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        result: int=0

        n: int=len(arr)

        arr.sort()

        if arr[0]!=1:
            arr[0]=1

        for index in range(1, n):
            difference: int=arr[index] - arr[index - 1]

            if difference > 1:
                arr[index]=arr[index - 1] + 1

        result=arr[n - 1]
        
        return result
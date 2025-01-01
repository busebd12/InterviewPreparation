class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return True

        n: int=len(arr)
        
        arr.sort()

        previous_difference: int=arr[1] - arr[0]

        for index in range(2, n):
            current_difference: int=arr[index] - arr[index - 1]

            if current_difference!=previous_difference:
                return False

            previous_difference=current_difference
        
        return True
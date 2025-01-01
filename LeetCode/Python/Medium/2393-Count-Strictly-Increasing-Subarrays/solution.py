class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        length: int=1

        previous: int=nums[0]

        for index in range(1, n):
            if nums[index] > previous:
                length+=1

                previous=nums[index]
            else:
                subarrays: int=self.get_number_of_subarrays(length)

                result+=subarrays

                length=1

                previous=nums[index]

        if length > 0:
            subarrays: int=self.get_number_of_subarrays(length)

            result+=subarrays

        return result
        
    def get_number_of_subarrays(self, length: int) -> int:
        return (length * (length + 1)) // 2
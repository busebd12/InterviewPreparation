class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        k: int=0

        i: int=0

        while i < n:
            j: int=i + 1

            while(j < n and nums[i]==nums[j]):
                j+=1

            nums[k]=nums[i]

            i=j

            result+=1

            k+=1

        return result
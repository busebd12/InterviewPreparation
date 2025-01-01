class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        result: List[int]=None

        n: int=len(nums)

        result=[-1 for _ in range(0, n)]

        i: int=0

        for index in range(0, n):
            j: int=nums[index]

            result[i]=nums[j]

            i+=1

        return result
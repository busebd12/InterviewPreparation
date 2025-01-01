class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result=list()

        n=len(nums)

        for i in range(0, n):
            number=abs(nums[i])

            index=number - 1

            if nums[index] < 0:
                result.append(number)
            else:
                nums[index]*=-1

        return result
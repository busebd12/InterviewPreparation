class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        result: int=0

        n: int=len(nums)

        count: int=0

        for index in range(0, n):
            if nums[index]==val:
                count+=1
            else:
                nums[index - count]=nums[index]

        for times in range(0, count):
            nums[n - 1 - times]=val

        result=n - count

        return result
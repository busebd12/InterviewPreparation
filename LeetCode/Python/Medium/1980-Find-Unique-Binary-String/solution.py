class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        result: str=""

        n: int=len(nums)

        digits: List[chr]=list()

        for index in range(0, n):
            if nums[index][index]=='0':
                digits.append('1')
            else:
                digits.append('0')

        result=''.join(digits)

        return result
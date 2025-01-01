class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        result: int=0
        
        stack: List[int]=list()

        for number in nums:
            while stack and number < stack[-1]:
                stack.pop()

            stack.append(number)

            result+=len(stack)

        return result
from collections import deque

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        result=list()

        positives=deque([number for number in nums if number > 0])

        negatives=deque([number for number in nums if number < 0])

        while positives or negatives:
            if positives:
                result.append(positives.popleft())

            if negatives:
                result.append(negatives.popleft())

        return result
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        result: int=0

        frequencies: Dict[int, int]=dict()

        for number in nums:
            if number not in frequencies.keys():
                frequencies[number]=1
            else:
                result+=frequencies[number]

                frequencies[number]+=1

        return result
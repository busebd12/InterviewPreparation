class Solution:
    def minOperations(self, nums: List[int]) -> int:
        result=0

        frequencies=dict()

        for number in nums:
            if number not in frequencies.keys():
                frequencies[number]=0

            frequencies[number]+=1

        for frequency in frequencies.values():
            if frequency==1:
                return -1

        for frequency in frequencies.values():
            times=frequency // 3

            left_over=frequency % 3

            if left_over==0:
                result+=times
            elif left_over==1:
                result+=(times - 1)

                result+=2
            elif left_over==2:
                result+=times

                result+=1

        return result
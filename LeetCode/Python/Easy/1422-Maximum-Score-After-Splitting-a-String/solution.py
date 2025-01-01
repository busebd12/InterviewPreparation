class Solution:
    def maxScore(self, s: str) -> int:
        result=0

        n=len(s)

        zeros_on_the_left=[0 for _ in range(0, n)]

        zeros=0

        for (index, digit) in enumerate(s):
            if digit=='0':
                zeros+=1

            zeros_on_the_left[index]=zeros

        ones_on_the_right=[0 for _ in range(0, n)]

        ones=0

        for index in range(n-1, -1, -1):
            digit=s[index]
            
            if digit=='1':
                ones+=1

            ones_on_the_right[index]=ones
        
        for index in range(1, n):
            zeros=zeros_on_the_left[index - 1]

            ones=ones_on_the_right[index]

            total=zeros + ones

            result=max(result, total)

        return result
class Solution:
    def isHappy(self, n: int) -> bool:
        seen: set(int)=set()

        while n!=1:
            sum: int=0

            while n > 0:
                digit: int=n % 10

                squared=pow(digit, 2)

                sum+=squared

                n//=10

            if sum in seen:
                return False
            
            seen.add(sum)

            n=sum

        return True
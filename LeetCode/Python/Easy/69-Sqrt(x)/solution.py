class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:
            return 0

        result: int=0

        low: int=1

        high: int=x

        while low <= high:
            square_root: int=(low + (high - low)//2)

            if square_root * square_root == x:
                return square_root
            elif square_root * square_root > x:
                high=square_root - 1
                
            #In the case where the square_root squared is less than x, the square_root
            #value could possibly be the answer since we are rounding down
            #Consider the example case where x is 8: the floating square root value is 2.82842...
            #but we are only interested in the whole integer value so we round down to 2
            #We store 2 in result since 2^2 is less than 8 and so it could be our answer but
            #we could still find another value larger than two that when squared is still less than eight.
            #That's why we set low=square_root + 1, to continue to search for that potentially larger value
            elif square_root * square_root < x: 
                result=square_root

                low=square_root + 1
        
        return result
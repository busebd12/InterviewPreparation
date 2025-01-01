from collections import deque

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        number_string: str=str(x)

        digits: int=len(number_string)

        left: int=0

        right: int=digits - 1

        while left < right:
            if number_string[left]!=number_string[right]:
                return False

            left+=1

            right-=1

        return True


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        digits: deque[int]=self.get_digits(x)

        return self.check(digits)

    def get_digits(self, x: int) -> deque[int]:
        digits: deque[int]=deque()

        while x > 0:
            digit: int=x % 10

            digits.appendleft(digit)

            x//=10

        return digits

    def check(self, digits: deque[int]) -> bool:
        d: int=len(digits)

        left: int=0

        right: int=d - 1

        while left < right:
            if digits[left]!=digits[right]:
                return False

            left+=1

            right-=1

        return True
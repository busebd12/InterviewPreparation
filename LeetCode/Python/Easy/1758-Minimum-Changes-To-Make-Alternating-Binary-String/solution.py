class Solution:
    def minOperations(self, s: str) -> int:
        result=0

        n=len(s)

        start='0'

        alternating=self.generate_alternating_string(n, start)

        result=self.count_differences(s, alternating, n)

        start='1'

        alternating=self.generate_alternating_string(n, start)

        result=min(result, self.count_differences(s, alternating, n))

        return result

    def generate_alternating_string(self, n: int, start: chr) -> List[chr]:
        digits=['$' for _ in range(0, n)]

        digits[0]=start

        for index in range(1, n):
            if digits[index - 1]=='0':
                digits[index]='1'
            else:
                digits[index]='0'

        return digits

    def count_differences(self, s: str, alternating: str, n: int) -> int:
        differences=0

        for index in range(0, n):
            if s[index]!=alternating[index]:
                differences+=1

        return differences
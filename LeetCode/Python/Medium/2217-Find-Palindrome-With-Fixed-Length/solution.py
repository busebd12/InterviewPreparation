from collections import deque

class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        result=list()

        q=len(queries)

        result=[-1 for _ in range(0, q)]

        half_of_palindrome_length=(intLength + 1)//2

        first_palindrome_half=10**(half_of_palindrome_length - 1)

        last_palindrome_half=(10**half_of_palindrome_length) - 1

        number_of_palindromes=(last_palindrome_half - first_palindrome_half) + 1

        for index in range(0, q):
            query=queries[index]

            if query <= number_of_palindromes:
                first_half_of_palindrome=str(first_palindrome_half + query - 1)

                queue=deque()

                middle=(half_of_palindrome_length - 1) if (intLength % 2)==1 else half_of_palindrome_length

                for iteration in range(0, middle):
                    queue.appendleft(first_half_of_palindrome[iteration])

                second_half_of_palindrome_digits=list()

                while queue:
                    second_half_of_palindrome_digits.append(queue.popleft())

                second_half_of_palindrome="".join(second_half_of_palindrome_digits)

                combined=first_half_of_palindrome + second_half_of_palindrome

                result[index]=int(combined)

        return result

class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        result=list()

        q=len(queries)

        result=[-1 for _ in range(0, q)]

        half_of_palindrome_length=(intLength + 1)//2

        first_palindrome_half=10**(half_of_palindrome_length - 1)

        last_palindrome_half=(10**half_of_palindrome_length) - 1

        number_of_palindromes=(last_palindrome_half - first_palindrome_half) + 1

        for index in range(0, q):
            query=queries[index]

            if query <= number_of_palindromes:
                first_half_of_palindrome=first_palindrome_half + query - 1

                first_half_of_palindrome_digits=deque()

                while first_half_of_palindrome > 0:
                    first_half_of_palindrome_digits.appendleft(first_half_of_palindrome % 10)

                    first_half_of_palindrome//=10

                middle=(half_of_palindrome_length - 1) if (intLength % 2)==1 else half_of_palindrome_length

                second_half_of_palindrome_digits=deque()

                for iteration in range(0, middle):
                    second_half_of_palindrome_digits.append(first_half_of_palindrome_digits[iteration])

                combined_palindrome_digits=deque()

                while first_half_of_palindrome_digits:
                    combined_palindrome_digits.append(first_half_of_palindrome_digits.popleft())

                while second_half_of_palindrome_digits:
                    combined_palindrome_digits.append(second_half_of_palindrome_digits.pop())

                combined=0

                while combined_palindrome_digits:
                    combined=(combined * 10) + combined_palindrome_digits.popleft()

                result[index]=combined

        return result
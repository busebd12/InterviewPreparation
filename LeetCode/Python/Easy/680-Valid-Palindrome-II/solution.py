class Solution:
    def validPalindrome(self, s: str) -> bool:
        n: int=len(s)

        letters: List[chr]=['$'] * n

        for index in range(0, n):
            letters[index]=s[index]

        left_mismatch_index, right_mismatch_index=self.get_mismatch_indices(s, n)

        if left_mismatch_index==-1 and right_mismatch_index==-1:
            return True

        letters[right_mismatch_index]='$'

        dollar_sign_on_left: bool=False

        if self.is_palindrome(letters, n, dollar_sign_on_left):
            return True

        for index in range(0, n):
            letters[index]=s[index]

        letters[left_mismatch_index]='$'

        dollar_sign_on_left=True

        return self.is_palindrome(letters, n, dollar_sign_on_left)

    def get_mismatch_indices(self, s: str, n: int) -> Tuple[int, int]:
        left: int=0

        right: int=n-1

        left_mismatch_index: int=-1

        right_mismatch_index: int=-1

        while left < right:
            if s[left]!=s[right]:
                left_mismatch_index=left

                right_mismatch_index=right

                break

            left+=1

            right-=1

        return (left_mismatch_index, right_mismatch_index)

    def is_palindrome(self, letters: List[chr], n: int, dollar_sign_on_left: bool) -> bool:
        left: int=0

        right: int=n-1

        if dollar_sign_on_left:
            while left < right:
                while left < right and letters[left]=='$':
                    left+=1

                if letters[left]!=letters[right]:
                    return False

                left+=1

                right-=1

            return True
        else:
            while left < right:
                while right > left and letters[right]=='$':
                    right-=1

                if letters[left]!=letters[right]:
                    return False

                left+=1

                right-=1

            return True
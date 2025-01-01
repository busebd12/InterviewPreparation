class Solution:
    def __init__(self):
        self.memo=list()

    def isValidPalindrome(self, s: str, k: int) -> bool:
        result=0

        n=len(s)

        self.memo=[[-1 for _ in range(0, n)] for _ in range(0, n)]

        left=0

        right=n-1

        length_of_longest_palindromic_subsequence=self.get_longest_palindromic_subsequence(s, left, right)

        return n - length_of_longest_palindromic_subsequence <= k

    def get_longest_palindromic_subsequence(self, s: int, left: int, right: int) -> int:
        if left==right:
            return 1
        
        if left > right:
            return 0

        if self.memo[left][right]!=-1:
            return self.memo[left][right]

        subproblem_solution=0

        if s[left]==s[right]:
            subproblem_solution=2 + self.get_longest_palindromic_subsequence(s, left + 1, right - 1)
        else:
            pick_left_character=self.get_longest_palindromic_subsequence(s, left, right - 1)

            pick_right_character=self.get_longest_palindromic_subsequence(s, left + 1, right)

            subproblem_solution=max(pick_left_character, pick_right_character)

        self.memo[left][right]=subproblem_solution
        
        return subproblem_solution
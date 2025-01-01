class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)

        left=0

        right=n-1

        result=self.helper(s, left, right)

        return result

    def helper(self, s: str, left: int, right: int) -> int:
        if left==right:
            return 1
        
        if left > right:
            return 0

        subproblem_solution=0

        if s[left]==s[right]:
            subproblem_solution=2 + self.helper(s, left + 1, right - 1)
        else:
            pick_left_character=self.helper(s, left, right - 1)

            pick_right_character=self.helper(s, left + 1, right)

            subproblem_solution=max(pick_left_character, pick_right_character)
        
        return subproblem_solution

class Solution:
    def __init__(self):
        self.memo=list()

    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)

        self.memo=[[-1 for _ in range(0, n)] for _ in range(0, n)]

        left=0

        right=n-1

        result=self.helper(s, left, right)

        return result

    def helper(self, s: str, left: int, right: int) -> int:
        if left==right:
            return 1
        
        if left > right:
            return 0

        if self.memo[left][right]!=-1:
            return self.memo[left][right]

        subproblem_solution=0

        if s[left]==s[right]:
            subproblem_solution=2 + self.helper(s, left + 1, right - 1)
        else:
            pick_left_character=self.helper(s, left, right - 1)

            pick_right_character=self.helper(s, left + 1, right)

            subproblem_solution=max(pick_left_character, pick_right_character)

        self.memo[left][right]=subproblem_solution
        
        return subproblem_solution
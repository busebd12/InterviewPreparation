'''
Solution 1: pure recursion. Note: this solution will get time limit exceeded when submitted. DO NOT submit this one!!!
'''
class Solution:
    def numWays(self, n: int, k: int) -> int:
        result=0

        previous_color=-1

        previous_two_fences_the_same_color=0

        result=self.helper(n, k, previous_color, previous_two_fences_the_same_color)

        return result

    def helper(self, n: int, k: int, previous_color: int, previous_two_fences_the_same_color: int) -> int:
        if n==0:
            return 1

        subproblem_solution=0

        for next_color in range(0, k):
            if previous_color==next_color and previous_two_fences_the_same_color:
                continue

            subproblem_solution+=self.helper(n - 1, k, next_color, int(previous_color==next_color))

        return subproblem_solution

'''
Solution 2: recursion + memoization. The online judge accepts this solution.
'''
class Solution:
    def numWays(self, n: int, k: int) -> int:
        result=0

        previous_color=-1

        previous_two_fences_the_same_color=0

        memo=[[-1 for _ in range(0, 2)] for _ in range(0, n + 1)]

        result=self.helper(memo, n, k, previous_color, previous_two_fences_the_same_color)

        return result

    def helper(self, memo: List[List[int]], n: int, k: int, previous_color: int, previous_two_fences_the_same_color: int) -> int:
        if n==0:
            return 1

        if memo[n][previous_two_fences_the_same_color]!=-1:
            return memo[n][previous_two_fences_the_same_color]

        subproblem_solution=0

        for next_color in range(0, k):
            if previous_color==next_color and previous_two_fences_the_same_color:
                continue

            subproblem_solution+=self.helper(memo, n - 1, k, next_color, int(previous_color==next_color))

        memo[n][previous_two_fences_the_same_color]=subproblem_solution

        return subproblem_solution
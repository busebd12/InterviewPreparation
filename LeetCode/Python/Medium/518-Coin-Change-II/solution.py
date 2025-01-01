'''
Solution 1: pure recursion. Note, this solution receives Time Limit Exceeded when run. DO NOT SUBMIT this solution!!!
I have only included it so you can see how we go from the recursive solution to the solution using recursion + memoization
'''
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        result: int=0

        n: int=len(coins)

        index: int=0

        result=self.solve(coins, n, amount, index)

        return result

    def solve(self, coins: List[int], n: int, amount: int, index: int) -> int:
        if amount==0:
            return 1

        if index >= n or amount < 0:
            return 0

        subproblem_solution: int=0

        take_coin: int=self.solve(coins, n, amount - coins[index], index)

        skip_coin: int=self.solve(coins, n, amount, index + 1)

        subproblem_solution=take_coin + skip_coin

        return subproblem_solution

#Solution 2: recursion + memoization
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        result: int=0

        n: int=len(coins)

        memo: List[List[int]]=[[-1 for iteration in range(0, n + 1)] for iteration in range(0, amount + 1)]

        index: int=0

        result=self.solve(coins, memo, n, amount, index)

        return result

    def solve(self, coins: List[int], memo: List[List[int]], n: int, amount: int, index: int) -> int:
        if amount==0:
            return 1

        if index >= n or amount < 0:
            return 0

        if memo[amount][index]!=-1:
            return memo[amount][index]

        subproblem_solution: int=0

        take_coin: int=self.solve(coins, memo, n, amount - coins[index], index)

        skip_coin: int=self.solve(coins, memo, n, amount, index + 1)

        subproblem_solution=take_coin + skip_coin

        memo[amount][index]=subproblem_solution

        return subproblem_solution
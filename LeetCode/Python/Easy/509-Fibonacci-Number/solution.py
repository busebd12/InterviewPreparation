class Solution:
    def fib(self, n: int) -> int:
        return self.helper(n)

    def helper(self, n: int) -> int:
        if n==0:
            return 0

        if n==1:
            return 1

        subproblem_solution: int=0

        subproblem_solution=self.helper(n - 2) + self.helper(n - 1)

        return subproblem_solution

class Solution:
    __memo=None
    
    def fib(self, n: int) -> int:
        self.__memo=[-1] * (n + 1)
        
        return self.helper(n)

    def helper(self, n: int) -> int:
        if n==0:
            return 0

        if n==1:
            return 1

        if self.__memo[n]!=-1:
            return self.__memo[n]

        subproblem_solution: int=0

        subproblem_solution=self.helper(n - 2) + self.helper(n - 1)

        self.__memo[n]=subproblem_solution

        return subproblem_solution

class Solution:
    def fib(self, n: int) -> int:
        if n==0:
            return 0

        if n==1:
            return 1
        
        dp: list[int]=[-1] * (n + 1)
        
        dp[0]=0

        dp[1]=1

        for index in range(2, n + 1):
            dp[index]=dp[index - 1] + dp[index - 2]
        
        return dp[n]
class Solution:
    def climbStairs(self, n: int) -> int:
        return self.helper(n)

    def helper(self, n: int) -> int:
        if n <= 1:
            return 1
        
        subproblem_solution: int=0

        take_one_step: int=self.helper(n - 1)

        take_two_step: int=self.helper(n - 2)

        subproblem_solution=take_one_step + take_two_step

        return subproblem_solution

class Solution:
    __memo: dict[int, int]=None
    
    def climbStairs(self, n: int) -> int:
        self.__memo=dict()
        
        return self.helper(n)

    def helper(self, n: int) -> int:
        if n <= 1:
            return 1

        if n in self.__memo:
            return self.__memo[n]
        
        subproblem_solution: int=0

        take_one_step: int=self.helper(n - 1)

        take_two_step: int=self.helper(n - 2)

        subproblem_solution=take_one_step + take_two_step

        self.__memo[n]=subproblem_solution

        return subproblem_solution

class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1

        limit: int=n + 1

        dp: List[int]=[0] * limit
        
        dp[0]=0

        dp[1]=1

        dp[2]=2

        index: int=3

        while index <= n:
            dp[index]=dp[index - 1] + dp[index - 2]

            index+=1

        return dp[n]
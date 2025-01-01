class Solution:
    def __init__(self):
        self.memo=list()

    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        result=0

        self.memo=[[-1 for _ in range(0, target + 1)] for _ in range(0, n + 1)]

        result=self.helper(n, k, target)

        MOD=(10**9) + 7

        return result % MOD

    def helper(self, n: int, k: int, target: int) -> int:
        if target < 0:
            return 0

        if n==1 and k < target and target > 0:
            return 0
        
        if n==1 and k >= target and target > 0:
            return 1

        if self.memo[n][target]!=-1:
            return self.memo[n][target]

        subproblem_solution=0
        
        for face in range(1, k + 1):
            subproblem_solution+=self.helper(n - 1, k, target - face)

        self.memo[n][target]=subproblem_solution

        return subproblem_solution
'''
Solution 1: pure recursion. This solution receives Time Limit Exceeded when run. DO NOT submit this!!!
'''
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        result=0

        n=len(text1)
        
        m=len(text2)

        i=0
        
        j=0

        result=self.helper(text1, text2, n, m, i, j)

        return result

    def helper(self, text1: str, text2: str, n: int, m: int, i: int, j: int) -> int:
        if i >= n or j >= m:
            return 0

        subproblem_solution=0

        if text1[i]==text2[j]:
            subproblem_solution=1 + self.helper(text1, text2, n, m, i + 1, j + 1)
        else:
            subproblem_solution=max(self.helper(text1, text2, n, m, i + 1, j), self.helper(text1, text2, n, m, i, j + 1))

        return subproblem_solution

'''
Solution 2: recursion + memoization
'''
class Solution:
    def __init__(self):
        self.memo=list()
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        result=0

        n=len(text1)
        
        m=len(text2)

        self.memo=[[-1 for _ in range(0, m)] for _ in range(0, n)]

        i=0
        
        j=0

        result=self.helper(text1, text2, n, m, i, j)

        return result

    def helper(self, text1: str, text2: str, n: int, m: int, i: int, j: int) -> int:
        if i >= n or j >= m:
            return 0

        if self.memo[i][j]!=-1:
            return self.memo[i][j]

        subproblem_solution=0

        if text1[i]==text2[j]:
            subproblem_solution=1 + self.helper(text1, text2, n, m, i + 1, j + 1)
        else:
            subproblem_solution=max(self.helper(text1, text2, n, m, i + 1, j), self.helper(text1, text2, n, m, i, j + 1))

        self.memo[i][j]=subproblem_solution
        
        return subproblem_solution
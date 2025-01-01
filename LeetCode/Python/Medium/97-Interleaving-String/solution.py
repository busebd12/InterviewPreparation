'''
Solution 1: pure recursion.
IMPORTANT: this solution receives Time Limit Exceeded when run. DO NOT submit it!
I have only included it so it can be seen how the recursive solution with memoization solution is derived.
'''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        result: bool=False

        s1_length: int=len(s1)

        s2_length: int=len(s2)

        s3_length: int=len(s3)

        if (s1_length + s2_length)!=s3_length:
            return False

        i: int=0

        j: int=0

        k: int=0

        result=self.solve(s1, s2, s3, s1_length, s2_length, s3_length, i, j, k)

        return result

    def solve(self, s1: str, s2: str, s3: str, s1_length: int, s2_length: int, s3_length: int, i: int, j: int, k: int) -> bool:
        if i==s1_length and j==s2_length and k==s3_length:
            return True

        if i==s1_length:
            return s2[j : ]==s3[k : ]

        if j==s2_length:
            return s1[i : ]==s3[k : ]

        subproblem_solution: bool=False

        if s1[i]==s3[k]:
            subproblem_solution=subproblem_solution or self.solve(s1, s2, s3, s1_length, s2_length, s3_length, i + 1, j, k + 1)

        if s2[j]==s3[k]:
            subproblem_solution=subproblem_solution or self.solve(s1, s2, s3, s1_length, s2_length, s3_length, i, j + 1, k + 1)

        return subproblem_solution

'''
Solution 2: recursion + memoization
'''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        result: bool=False

        s1_length: int=len(s1)

        s2_length: int=len(s2)

        s3_length: int=len(s3)

        if (s1_length + s2_length)!=s3_length:
            return False

        memo: List[List[List[int]]]=[[[-1 for _ in range(0, s3_length)] for _ in range(0, s2_length)] for _ in range(0, s1_length)]

        i: int=0

        j: int=0

        k: int=0

        result=self.solve(s1, s2, s3, memo, s1_length, s2_length, s3_length, i, j, k)

        return result

    def solve(self, s1: str, s2: str, s3: str, memo: List[List[List[int]]], s1_length: int, s2_length: int, s3_length: int, i: int, j: int, k: int) -> bool:
        
        if i==s1_length and j==s2_length and k==s3_length:
            return True

        if i==s1_length:
            return s2[j : ]==s3[k : ]

        if j==s2_length:
            return s1[i : ]==s3[k : ]

        if memo[i][j][k]!=-1:
            return memo[i][j][k]

        subproblem_solution: bool=False

        if s1[i]==s3[k]:
            subproblem_solution=subproblem_solution or self.solve(s1, s2, s3, memo, s1_length, s2_length, s3_length, i + 1, j, k + 1)

        if s2[j]==s3[k]:
            subproblem_solution=subproblem_solution or self.solve(s1, s2, s3, memo, s1_length, s2_length, s3_length, i, j + 1, k + 1)

        memo[i][j][k]=subproblem_solution

        return subproblem_solution
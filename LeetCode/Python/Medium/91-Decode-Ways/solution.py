class Solution:
    def numDecodings(self, s: str) -> int:
        result=0

        n=len(s)

        index=0

        result=self.helper(s, n, index)

        return result

    def helper(self, s: str, n: int, index: int) -> int:
        if index==n:
            return 1
        
        if s[index]=='0':
            return 0

        subproblem_solution=0

        if s[index]=='1':
            subproblem_solution+=self.helper(s, n, index + 1)

            if index + 1 < n:
                subproblem_solution+=self.helper(s, n, index + 2)
        elif s[index]=='2':
            subproblem_solution+=self.helper(s, n, index + 1)

            if index + 1 < n and ((int(s[index + 1]) >= 0 and int(s[index + 1]) <= 6)):
                subproblem_solution+=self.helper(s, n, index + 2)
        else:
            subproblem_solution+=self.helper(s, n, index + 1)
        
        return subproblem_solution

class Solution:
    def __init__(self):
        self.memo=list()

    def numDecodings(self, s: str) -> int:
        result=0

        n=len(s)

        self.memo=[-1 for _ in range(0, n + 1)]

        index=0

        result=self.helper(s, n, index)

        return result

    def helper(self, s: str, n: int, index: int) -> int:
        if index==n:
            return 1
        
        if s[index]=='0':
            return 0

        if self.memo[index]!=-1:
            return self.memo[index]

        subproblem_solution=0

        if s[index]=='1':
            subproblem_solution+=self.helper(s, n, index + 1)

            if index + 1 < n:
                subproblem_solution+=self.helper(s, n, index + 2)
        elif s[index]=='2':
            subproblem_solution+=self.helper(s, n, index + 1)

            if index + 1 < n and ((int(s[index + 1]) >= 0 and int(s[index + 1]) <= 6)):
                subproblem_solution+=self.helper(s, n, index + 2)
        else:
            subproblem_solution+=self.helper(s, n, index + 1)

        self.memo[index]=subproblem_solution
        
        return subproblem_solution
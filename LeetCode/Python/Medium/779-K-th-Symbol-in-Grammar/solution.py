class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        result: int=0

        result=self.helper(n, k)

        return result
    
    def helper(self, n: int, k: int) -> int:
        if n==1:
            if k==1:
                return 0
            else:
                return 1
        
        subproblem_solution: int=-1

        row_size: int=2**(n - 1)

        half_index: int=row_size // 2

        if k <= half_index:
            subproblem_solution=self.helper(n - 1, k)
        else:
            digit: int=self.helper(n - 1, k - half_index)

            if digit==0:
                subproblem_solution=1
            else:
                subproblem_solution=0

        return subproblem_solution
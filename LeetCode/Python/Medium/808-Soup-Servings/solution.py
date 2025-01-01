'''
Solution 1: pure recusion. NOTE: this solution receives Time Limit Exceeded when run so DO NOT submit it.
I've only included it to show how the memoized solution is derived from the recursive one
'''
class Solution:
    def soupServings(self, n: int) -> float:
        result: float=0

        operations: Tuple[Tuple[int, int]]=((100, 0), (75, 25), (50, 50), (25, 75))

        soup_a: int=n

        soup_b: int=n

        result=self.helper(operations, soup_a, soup_b)

        return result

    def helper(self, operations: Tuple[Tuple[int, int]], soup_a: int, soup_b: int) -> float:
        if soup_a > 0 and soup_b <= 0:
            return 0.0
        
        if soup_a <= 0 and soup_b <= 0:
            return 0.5

        if soup_a <= 0 and soup_b > 0:
            return 1.0

        subproblem_solution: float=0.0

        for operation in operations:
            subproblem_solution+=self.helper(operations, soup_a - operation[0], soup_b - operation[1])

        subproblem_solution*=0.25

        return subproblem_solution

#Solution 2: recursion + memoization. This solution is accepted.
class Solution:
    def soupServings(self, n: int) -> float:
        #According to the discussion section, once n exceeds 4800, the probability is so close to 1 that the answer will always be 1
        if n > 4800:
            return 1.0
        
        result: float=0

        #memo: List[List[int]]=[[-1 for _ in range(0, n + 1)] for _ in range(0, n + 1)]

        memo: List[List[int]]=[[-1] (n + 1) for _ in range(0, n + 1)]

        operations: Tuple[Tuple[int, int]]=((100, 0), (75, 25), (50, 50), (25, 75))

        soup_a: int=n

        soup_b: int=n

        result=self.helper(memo, operations, soup_a, soup_b)

        return result

    def helper(self, memo: List[List[int]], operations: Tuple[Tuple[int, int]], soup_a: int, soup_b: int) -> float:
        if soup_a > 0 and soup_b <= 0:
            return 0.0
        
        if soup_a <= 0 and soup_b <= 0:
            return 0.5

        if soup_a <= 0 and soup_b > 0:
            return 1.0

        if memo[soup_a][soup_b]!=-1:
            return memo[soup_a][soup_b]

        subproblem_solution: float=0.0

        for operation in operations:
            subproblem_solution+=self.helper(memo, operations, soup_a - operation[0], soup_b - operation[1])

        subproblem_solution*=0.25

        memo[soup_a][soup_b]=subproblem_solution

        return subproblem_solution

#Solution 3: another recursive + memoization solution. Also, accepted.
class Solution:
    def soupServings(self, n: int) -> float:
        if n > 4800:
            return 1.0
        
        result: float=0

        #memo: List[List[int]]=[[-1 for _ in range(0, n + 1)] for _ in range(0, n + 1)]

        memo: Dict[Tuple[int, int], float]=dict()

        operations: Tuple[Tuple[int, int]]=((100, 0), (75, 25), (50, 50), (25, 75))

        soup_a: int=n

        soup_b: int=n

        result=self.helper(memo, operations, soup_a, soup_b)

        return result

    def helper(self, memo: Dict[Tuple[int, int], float], operations: Tuple[Tuple[int, int]], soup_a: int, soup_b: int) -> float:
        if soup_a > 0 and soup_b <= 0:
            return 0.0
        
        if soup_a <= 0 and soup_b <= 0:
            return 0.5

        if soup_a <= 0 and soup_b > 0:
            return 1.0

        key: Tuple[int, int]=(soup_a, soup_b)

        if key in memo.keys():
            return memo[key]

        subproblem_solution: float=0.0

        for operation in operations:
            subproblem_solution+=self.helper(memo, operations, soup_a - operation[0], soup_b - operation[1])

        subproblem_solution*=0.25

        memo[key]=subproblem_solution

        return subproblem_solution
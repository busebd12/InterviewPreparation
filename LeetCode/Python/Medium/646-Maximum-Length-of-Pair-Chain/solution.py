'''
Solution 1: pure recursion.
IMPORTANT: this solution receives Time Limit Exceeded when run. DO NOT submit it!
I have only included it so that you can see how we go from the recursive solution to the memoized solution.
'''
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        result: int=0

        n: int=len(pairs)

        pairs.sort(key=lambda pair: pair[0])

        previous: int=-10001

        index: int=0

        result=self.solve(pairs, n, previous, index)

        return result
    
    def solve(self, pairs: List[List[int]], n: int, previous: int, index: int) -> int:
        if index==n:
            return 0

        subproblem_solution: int=0

        take_pair: int=0

        if previous < pairs[index][0]:
            take_pair=1 + self.solve(pairs, n, pairs[index][1], index + 1)
        
        skip_pair: int=self.solve(pairs, n, previous, index + 1)

        subproblem_solution=max(take_pair, skip_pair)

        return subproblem_solution

'''
Solution 2: recursion + memoization
'''
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        result: int=0

        n: int=len(pairs)

        memo: Dict[Tuple[int, int], int]=dict()

        pairs.sort(key=lambda pair: pair[0])

        previous: int=-10001

        index: int=0

        result=self.solve(pairs, memo, n, previous, index)

        return result
    
    def solve(self, pairs: List[List[int]], memo: Dict[Tuple[int, int], int], n: int, previous: int, index: int) -> int:
        if index==n:
            return 0

        key: Tuple[int, int]=(index, previous)

        if key in memo.keys():
            return memo[key]

        subproblem_solution: int=0

        take_pair: int=0

        if previous < pairs[index][0]:
            take_pair=1 + self.solve(pairs, memo, n, pairs[index][1], index + 1)
        
        skip_pair: int=self.solve(pairs, memo, n, previous, index + 1)

        subproblem_solution=max(take_pair, skip_pair)

        memo[key]=subproblem_solution

        return subproblem_solution

'''
Solution 3: greedy
'''
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        result: int=0

        n: int=len(pairs)

        pairs.sort(key=lambda pair: pair[1])

        previous: int=-10001

        for pair in pairs:
            if previous < pair[0]:
                previous=pair[1]
                
                result+=1

        return result
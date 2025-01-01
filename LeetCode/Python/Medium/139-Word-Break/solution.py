'''
Solution 1: pure recursion.
Note: this solution receives Time Limit Exceed when run. DO NOT SUBMIT this solution!!!
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n: int=len(s)

        hashset: Set[str]=set(wordDict)

        start: int=0

        return self.helper(s, hashset, n, start)

    def helper(self, s: str, hashset: Set[str], n: int, start: int) -> bool:
        if start >= n:
            return True

        subproblem_solution: bool=False

        for index in range(start + 1, n + 1):
            prefix: str=s[start : index]

            prefix_length: int=index - start

            if prefix in hashset:
                if self.helper(s, hashset, n, start + prefix_length):
                    subproblem_solution=True

                    return subproblem_solution

        return subproblem_solution

'''
Solution 2: recursion + memoization.
This solution is accepted by the online judge.
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n: int=len(s)

        memo: List[int]=[-1] * (n + 1)

        hashset: Set[str]=set(wordDict)

        start: int=0

        return self.helper(s, memo, hashset, n, start)

    def helper(self, s: str, memo: List[int], hashset: Set[str], n: int, start: int) -> bool:
        if start >= n:
            return True

        if memo[start]!=-1:
            return memo[start]

        subproblem_solution: bool=False

        for index in range(start + 1, n + 1):
            prefix: str=s[start : index]

            prefix_length: int=index - start

            if prefix in hashset:
                if self.helper(s, memo, hashset, n, start + prefix_length):
                    subproblem_solution=True

                    memo[start]=subproblem_solution

                    return subproblem_solution

        memo[start]=subproblem_solution

        return subproblem_solution
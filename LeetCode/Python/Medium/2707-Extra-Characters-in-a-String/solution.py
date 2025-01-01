'''
Solution 1: pure recursion.
IMPORTANT: this solution receives Time Limit Exceeded when run. DO NOT submit this solution.
I have only included it so it can be seen how the recursive memoization solution is derived from the pure recursive solution
'''
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        result: int=0

        n: int=len(s)

        hashset: Set[str]=set(dictionary)

        start: int=0

        result=self.solve(hashset, s, n, start)

        return result

    def solve(self, hashset: Set[str], s: str, n: int, start: int) -> int:
        if start==n:
            return 0

        subproblem_solution: int=0

        #Skip this index and start looking for words from the dictionary at the next index
        skip: int=1 + self.solve(hashset, s, n, start + 1)

        take: int=pow(2, 53) - 1

        #Iterate through all possible substrings start from the current index start
        for index in range(start + 1, n + 1):
            prefix: str=s[start : index]

            prefix_length: int=len(prefix)

            #If the prefix is in the dictionary
            if prefix in hashset:
                take=min(take, self.solve(hashset, s, n, start + prefix_length))

        subproblem_solution=min(skip, take)

        return subproblem_solution

'''
Solution 2: using recursion + memoization
'''
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        result: int=0

        n: int=len(s)

        memo: List[int]=[-1 for _ in range(0, n + 1)]

        hashset: Set[str]=set(dictionary)

        start: int=0

        result=self.solve(memo, hashset, s, n, start)

        return result

    def solve(self, memo: List[int], hashset: Set[str], s: str, n: int, start: int) -> int:
        if start==n:
            return 0

        if memo[start]!=-1:
            return memo[start]

        subproblem_solution: int=0

        #Skip this index and start looking for words from the dictionary at the next index
        skip: int=1 + self.solve(memo, hashset, s, n, start + 1)

        take: int=pow(2, 53) - 1

        #Iterate through all possible substrings start from the current index start
        for index in range(start + 1, n + 1):
            prefix: str=s[start : index]

            prefix_length: int=len(prefix)

            #If the prefix is in the dictionary
            if prefix in hashset:
                take=min(take, self.solve(memo, hashset, s, n, start + prefix_length))

        subproblem_solution=min(skip, take)

        memo[start]=subproblem_solution

        return subproblem_solution
#Solution 1: pure recursion. DO NOT SUBMIT! This solution gets Time Limit Exceeded when run.
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        result: int=0

        n: int=len(s1)

        m: int=len(s2)

        i: int=n - 1
        
        j: int=m - 1

        longest_common_subsequence_ascii_sum=self.get_longest_common_subsequence_ascii_sum(s1, s2, i, j)

        result=longest_common_subsequence_ascii_sum

        return result

    def get_longest_common_subsequence_ascii_sum(self, s1: str, s2: str, i: int, j: int) -> int:
        if i < 0 and j < 0:
            return 0

        if i < 0:
            return self.get_longest_common_subsequence_ascii_sum(s1, s2, i, j - 1) + ord(s2[j])

        if j < 0:
            return self.get_longest_common_subsequence_ascii_sum(s1, s2, i - 1, j) + ord(s1[i])

        if s1[i]==s2[j]:
            return self.get_longest_common_subsequence_ascii_sum(s1, s2, i - 1, j - 1)

        else:
            return min(self.get_longest_common_subsequence_ascii_sum(s1, s2, i - 1, j) + ord(s1[i]), self.get_longest_common_subsequence_ascii_sum(s1, s2, i, j - 1) + ord(s2[j]))


#Solution 2: recursion + memoization. This solution passes the online judge.
class Solution:
    def __init__(self):
        self.memo: List[List[int]]=None

    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        result: int=0

        n: int=len(s1)

        m: int=len(s2)

        self.memo=[[-1 for _ in range(0, m + 1)] for _ in range(0, n + 1)]

        i: int=n - 1
        
        j: int=m - 1

        longest_common_subsequence_ascii_sum=self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i, j)

        result=longest_common_subsequence_ascii_sum

        return result

    def get_longest_common_subsequence_ascii_sum(self, memo: List[List[int]], s1: str, s2: str, i: int, j: int) -> int:
        if i < 0 and j < 0:
            return 0

        if self.memo[i][j]!=-1:
            return memo[i][j]

        subproblem_solution: int=0

        if i < 0:
            subproblem_solution=self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i, j - 1) + ord(s2[j])       
        elif j < 0:
            subproblem_solution=self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i - 1, j) + ord(s1[i])       
        elif s1[i]==s2[j]:
            subproblem_solution=self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i - 1, j - 1)
        else:
            subproblem_solution=min(self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i - 1, j) + ord(s1[i]), self.get_longest_common_subsequence_ascii_sum(self.memo, s1, s2, i, j - 1) + ord(s2[j]))

        self.memo[i][j]=subproblem_solution

        return subproblem_solution
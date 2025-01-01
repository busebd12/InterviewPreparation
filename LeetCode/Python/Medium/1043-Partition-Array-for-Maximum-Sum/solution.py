'''
Solution 1: pure recursive solution. Note: this solution gets Time Limit Exceeded when run. DO NOT submit this one!
'''
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        result=0

        n=len(arr)

        index=0

        result=self.helper(arr, n, k, index)

        return result

    def helper(self, arr: List[int], n: int, k: int, index: int) -> int:
        if index >= n:
            return 0

        subproblem_solution=0

        subarray_max=0

        stop=min(index + k, n)

        for i in range(index, stop):
            subarray_max=max(subarray_max, arr[i])

            subarray_length=(i - index) + 1

            subarray_sum=subarray_max * subarray_length

            recursive_call_solution=subarray_sum + self.helper(arr, n, k, i + 1)

            subproblem_solution=max(subproblem_solution, recursive_call_solution)

        return subproblem_solution

'''
Solution 2: recursion + memoization.
This solution does pass the online judge.
'''
class Solution:
    def __init__(self):
        self.memo=list()

    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        result=0

        n=len(arr)

        self.memo=[-1 for _ in range(0, n)]

        index=0

        result=self.helper(arr, n, k, index)

        return result

    def helper(self, arr: List[int], n: int, k: int, index: int) -> int:
        if index >= n:
            return 0

        if self.memo[index]!=-1:
            return self.memo[index]

        subproblem_solution=0

        subarray_max=0

        stop=min(index + k, n)

        for i in range(index, stop):
            subarray_max=max(subarray_max, arr[i])

            subarray_length=(i - index) + 1

            subarray_sum=subarray_max * subarray_length

            recursive_call_solution=subarray_sum + self.helper(arr, n, k, i + 1)

            subproblem_solution=max(subproblem_solution, recursive_call_solution)

        self.memo[index]=subproblem_solution

        return subproblem_solution
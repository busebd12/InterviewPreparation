import bisect

'''
Solution 1: pure recursion. DO NOT submit this solution, it will get Time Limit Exceeded.
'''
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        result=0

        n=len(startTime)

        jobs=[[startTime[i], endTime[i], profit[i]] for i in range(0, n)]

        jobs.sort(key=lambda job: job[0])

        startTime.sort()

        index=0

        result=self.helper(jobs, startTime, n, index)

        return result

    def helper(self, jobs: List[List[int]], startTime: List[int], n: int, index: int) -> int:
        if index >= n:
            return 0

        subproblem_solution=0

        current_job_end_time=jobs[index][1]

        next_start_index=bisect.bisect_left(startTime, current_job_end_time)

        current_job_profit=jobs[index][2]

        include=current_job_profit + self.helper(jobs, startTime, n, next_start_index)

        exclude=self.helper(jobs, startTime, n, index + 1)

        subproblem_solution=max(include, exclude)

        return subproblem_solution

'''
Solution 2: recursion + memoization. This solution is accepted.
'''
class Solution:
    def __init__(self):
        self.memo=list()

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        result=0

        n=len(startTime)

        self.memo=[-1 for _ in range(0, n)]

        jobs=[[startTime[i], endTime[i], profit[i]] for i in range(0, n)]

        jobs.sort(key=lambda job: job[0])

        startTime.sort()

        index=0

        result=self.helper(jobs, startTime, n, index)

        return result

    def helper(self, jobs: List[List[int]], startTime: List[int], n: int, index: int) -> int:
        if index >= n:
            return 0

        if self.memo[index]!=-1:
            return self.memo[index]

        subproblem_solution=0

        current_job_end_time=jobs[index][1]

        next_start_index=bisect.bisect_left(startTime, current_job_end_time)

        current_job_profit=jobs[index][2]

        include=current_job_profit + self.helper(jobs, startTime, n, next_start_index)

        exclude=self.helper(jobs, startTime, n, index + 1)

        subproblem_solution=max(include, exclude)

        self.memo[index]=subproblem_solution

        return subproblem_solution
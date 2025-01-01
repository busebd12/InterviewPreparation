class Solution:
    def average(self, salary: List[int]) -> float:
        result: float=0

        n: int=len(salary)

        min_salary: int=min(salary)

        max_salary: int=max(salary)

        if min_salary!=max_salary:
            n-=2
        else:
            n-=1

        for amount in salary:
            if amount!=min_salary and amount!=max_salary:
                result+=amount

        result=result / n

        return result
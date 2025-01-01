from collections import deque

#Solution 1: breadth-first search
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        result: int=0

        coins.sort(reverse=True)

        queue: Deque[int]=deque()

        queue.append(amount)

        visited: Set[int]=set()

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                current: int=queue.popleft()

                if current==0:
                    return result

                for coin in coins:
                    next_amount: int=current - coin

                    if next_amount >= 0 and next_amount not in visited:
                        visited.add(next_amount)
                        
                        queue.append(next_amount)
            if queue:
                result+=1

        return -1

#Solution 2: breadth-first search
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        result: int=0

        coins.sort(reverse=True)

        queue: Deque[int]=deque()

        queue.append(amount)

        limit: int=100001

        visited: List[bool]=[False] * limit

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                current: int=queue.popleft()

                if current==0:
                    return result

                for coin in coins:
                    next_amount: int=current - coin

                    if next_amount >= 0 and not visited[next_amount]:
                        visited[next_amount]=True
                        
                        queue.append(next_amount)
            if queue:
                result+=1

        return -1

'''
Solution 3: pure recursion. Note, this solution receives Time Limit Exceeded when run. DO NOT submit it!
I have only included it so that you can see how we go from this solution to the solution using recursion and memoization.
'''
class Solution:
    def __init__(self):
        self.max_integer=pow(2, 53) - 1

    def coinChange(self, coins: List[int], amount: int) -> int:
        result: int=0

        coins.sort(reverse=True)

        limit: int=10001

        result=self.solve(coins, amount)

        return result if result!=self.max_integer else -1

    def solve(self, coins: List[int], amount: int) -> int:
        if amount==0:
            return 0

        subproblem_solution: int=self.max_integer

        for coin in coins:
            if amount - coin >= 0:
                subproblem_solution=min(subproblem_solution, 1 + self.solve(coins, amount - coin))

        return subproblem_solution

#Solution 4: recursion + memoization
class Solution:
    def __init__(self):
        self.max_integer=pow(2, 53) - 1

    def coinChange(self, coins: List[int], amount: int) -> int:
        result: int=0

        coins.sort(reverse=True)

        limit: int=10001

        memo: List[int]=[-1] * limit

        result=self.solve(coins, memo, amount)

        return result if result!=self.max_integer else -1

    def solve(self, coins: List[int], memo: List[int], amount: int) -> int:
        if amount==0:
            return 0

        if memo[amount]!=-1:
            return memo[amount]

        subproblem_solution: int=self.max_integer

        for coin in coins:
            if amount - coin >= 0:
                subproblem_solution=min(subproblem_solution, 1 + self.solve(coins, memo, amount - coin))

        memo[amount]=subproblem_solution

        return subproblem_solution
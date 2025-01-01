class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        result=0

        w=len(workers)

        b=len(bikes)

        used=[False for _ in range(0, b)]

        index=0

        result=self.backtrack(workers, bikes, used, w, b, index)

        return result

    def backtrack(self, workers: List[List[int]], bikes: List[List[int]], used: List[bool], w: int, b: int, index: int) -> int:
        if index==w:
            return 0

        subproblem_solution=float('inf')

        for bike_index in range(0, b):
            if used[bike_index]:
                continue
            
            used[bike_index]=True

            manhattan_distance=self.get_manhattan_distance(workers[index][0], workers[index][1], bikes[bike_index][0], bikes[bike_index][1])

            next_call=manhattan_distance + self.backtrack(workers, bikes, used, w, b, index + 1)

            subproblem_solution=min(subproblem_solution, next_call)

            used[bike_index]=False

        return subproblem_solution

    def get_manhattan_distance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)


class Solution:
    def __init__(self):
        self.memo=dict()

    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        result=0

        w=len(workers)

        b=len(bikes)

        used=[False for _ in range(0, b)]

        index=0

        result=self.backtrack(workers, bikes, used, w, b, index)

        return result

    def backtrack(self, workers: List[List[int]], bikes: List[List[int]], used: List[bool], w: int, b: int, index: int) -> int:
        if index==w:
            return 0

        key=tuple(used)

        if key in self.memo.keys():
            return self.memo[key]

        subproblem_solution=float('inf')

        for bike_index in range(0, b):
            if used[bike_index]:
                continue
            
            used[bike_index]=True

            manhattan_distance=self.get_manhattan_distance(workers[index][0], workers[index][1], bikes[bike_index][0], bikes[bike_index][1])

            next_call=manhattan_distance + self.backtrack(workers, bikes, used, w, b, index + 1)

            subproblem_solution=min(subproblem_solution, next_call)

            used[bike_index]=False

        self.memo[key]=subproblem_solution

        return subproblem_solution

    def get_manhattan_distance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)

        
class Solution:
    def __init__(self):
        self.memo=dict()

    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        result=0

        w=len(workers)

        b=len(bikes)

        mask=0

        index=0

        result=self.backtrack(workers, bikes, mask, w, b, index)

        return result

    def backtrack(self, workers: List[List[int]], bikes: List[List[int]], mask: int, w: int, b: int, index: int) -> int:
        if index==w:
            return 0

        if mask in self.memo.keys():
            return self.memo[mask]

        subproblem_solution=float('inf')

        for bike_index in range(0, b):
            bike_assigned=mask & (1 << bike_index)

            if bike_assigned:
                continue
            
            mask=mask | (1 << bike_index)

            manhattan_distance=self.get_manhattan_distance(workers[index][0], workers[index][1], bikes[bike_index][0], bikes[bike_index][1])

            next_call=manhattan_distance + self.backtrack(workers, bikes, mask, w, b, index + 1)

            subproblem_solution=min(subproblem_solution, next_call)

            mask=mask & ~(1 << bike_index)

        self.memo[mask]=subproblem_solution

        return subproblem_solution

    def get_manhattan_distance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)

        
class Solution:
    def __init__(self):
        self.memo=list()

    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        result=0

        self.memo=[-1 for _ in range(0, 1 << 10)]

        w=len(workers)

        b=len(bikes)

        mask=0

        index=0

        result=self.backtrack(workers, bikes, mask, w, b, index)

        return result

    def backtrack(self, workers: List[List[int]], bikes: List[List[int]], mask: int, w: int, b: int, index: int) -> int:
        if index==w:
            return 0

        if self.memo[mask]!=-1:
            return self.memo[mask]

        subproblem_solution=float('inf')

        for bike_index in range(0, b):
            bike_assigned=mask & (1 << bike_index)

            if bike_assigned:
                continue
            
            mask=mask | (1 << bike_index)

            manhattan_distance=self.get_manhattan_distance(workers[index][0], workers[index][1], bikes[bike_index][0], bikes[bike_index][1])

            next_call=manhattan_distance + self.backtrack(workers, bikes, mask, w, b, index + 1)

            subproblem_solution=min(subproblem_solution, next_call)

            mask=mask & ~(1 << bike_index)

        self.memo[mask]=subproblem_solution

        return subproblem_solution

    def get_manhattan_distance(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return abs(x1 - x2) + abs(y1 - y2)
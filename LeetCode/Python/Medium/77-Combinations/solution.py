import itertools

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result: List[List[int]]=list()

        combination: List[int]=list()

        start: int=1

        self.backtracking(result, combination, n, k, start)

        return result
    
    def backtracking(self, result: List[List[int]], combination: List[int], n: int, k: int, start: int) -> None:
        if len(combination)==k:
            result.append(combination.copy())

            return

        for number in range(start, n + 1):
            combination.append(number)

            self.backtracking(result, combination, n, k, number + 1)

            combination.pop()

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result: List[List[int]]=list()

        combinations=list(itertools.combinations(range(1, n + 1), k))

        result=[list(combination) for combination in combinations]

        return result
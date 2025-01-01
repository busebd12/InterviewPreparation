#Solution 1: recursive depth-first search like approach. WARNING: this solution gets Time Limit Exceeded when run. DO NOT SUBMIT!
#I have included it because it is used in the memoized approach for solutions two and three.
class Solution:
    __directions: Tuple[Tuple[int, int]]=None

    __moves=None

    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.__directions=((-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1))

        self.__moves=8

        return self.helper(n, k, row, column)

    def helper(self, n: int, k: int, row: int, column: int) -> float:
        if row < 0 or row >= n or column < 0 or column >= n:
            return 0.0

        if k==0:
            return 1.0

        subproblem_solution: float=0

        for (row_offset, column_offset) in self.__directions:
            next_row: int=row + row_offset

            next_column: int=column + column_offset

            path_result: float=self.helper(n, k - 1, next_row, next_column)

            subproblem_solution+=path_result

        return subproblem_solution / self.__moves


#Solution 2: memoized recursion using a hashmap based on the purely recursive solution.
class Solution:
    __memo: Dict[Tuple[int, int, int], int]=None
    
    __directions: Tuple[Tuple[int, int]]=None

    __moves: int=None

    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.__memo=dict()
        
        self.__directions=((-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1))

        self.__moves=8

        return self.helper(n, k, row, column)

    def helper(self, n: int, k: int, row: int, column: int) -> float:
        if row < 0 or row >= n or column < 0 or column >= n:
            return 0.0

        if k==0:
            return 1.0

        key: Tuple[int, int, int]=(row, column, k)

        if key in self.__memo.keys():
            return self.__memo[key]

        subproblem_solution: float=0

        for (row_offset, column_offset) in self.__directions:
            next_row: int=row + row_offset

            next_column: int=column + column_offset

            path_result: float=self.helper(n, k - 1, next_row, next_column)

            subproblem_solution+=path_result

        subproblem_solution/=self.__moves

        self.__memo[key]=subproblem_solution

        return subproblem_solution

#Solution 3: memoized recursion using a 3D list based on the purely recursive solution.
class Solution:
    __memo: List[List[List[int]]]=None
    
    __directions: Tuple[Tuple[int, int]]=None

    __moves: int=None

    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        self.__memo=[[[-1 for _ in range(0, k + 1)] for _ in range(0, n + 1)] for _ in range(0, n + 1)]
        
        self.__directions=((-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1))
        
        self.__moves=8

        return self.helper(n, k, row, column)

    def helper(self, n: int, k: int, row: int, column: int) -> float:
        if row < 0 or row >= n or column < 0 or column >= n:
            return 0.0

        if k==0:
            return 1.0

        if self.__memo[row][column][k]!=-1:
            return self.__memo[row][column][k]

        subproblem_solution: float=0

        for (row_offset, column_offset) in self.__directions:
            next_row: int=row + row_offset

            next_column: int=column + column_offset

            path_result: float=self.helper(n, k - 1, next_row, next_column)

            subproblem_solution+=path_result

        subproblem_solution/=self.__moves

        self.__memo[row][column][k]=subproblem_solution

        return subproblem_solution
'''
Solution 1: pure recursion.
IMPORTANT: this solution receives Time Limit Exceeded when run. DO NOT submit it.
I have only included it so it can be seen how the recursive + memoization solution is derived from the recursive solution.
'''
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        result: bool=False

        valid_positions: Set[int]=set(stones)

        last_stone: int=stones[-1]

        position: int=0

        previous_jump: int=0

        result=self.solve(stones, valid_positions, last_stone, position, previous_jump)

        return result
    
    def solve(self, stones: List[int], valid_positions: Set[int], last_stone: int, position: int, previous_jump: int) -> bool:
        if position not in valid_positions:
            return False

        if position==last_stone:
            return True

        subproblem_solution: bool=False

        k_minus_one: int=previous_jump - 1

        if k_minus_one > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, valid_positions, last_stone, position + k_minus_one, k_minus_one)

        k: int=previous_jump

        if k > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, valid_positions, last_stone, position + k, k)

        k_plus_one: int=previous_jump + 1

        if k_plus_one > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, valid_positions, last_stone, position + k_plus_one, k_plus_one)

        return subproblem_solution

'''
Solution 2: recursion + memoization
'''
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        result: bool=False

        valid_positions: Set[int]=set(stones)

        memo: Dict[Tuple[int, int], int]=dict()

        last_stone: int=stones[-1]

        position: int=0

        previous_jump: int=0

        result=self.solve(stones, memo, valid_positions, last_stone, position, previous_jump)

        return result
    
    def solve(self, stones: List[int], memo: Dict[Tuple[int, int], int], valid_positions: Set[int], last_stone: int, position: int, previous_jump: int) -> bool:
        if position not in valid_positions:
            return False

        if position==last_stone:
            return True

        key: Tuple[int, int]=(position, previous_jump)

        if key in memo.keys():
            return memo[key]

        subproblem_solution: bool=False

        k_minus_one: int=previous_jump - 1

        if k_minus_one > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, memo, valid_positions, last_stone, position + k_minus_one, k_minus_one)

        k: int=previous_jump

        if k > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, memo, valid_positions, last_stone, position + k, k)

        k_plus_one: int=previous_jump + 1

        if k_plus_one > 0:
            subproblem_solution=subproblem_solution or self.solve(stones, memo, valid_positions, last_stone, position + k_plus_one, k_plus_one)

        memo[key]=subproblem_solution

        return subproblem_solution

'''
Solution 3: More concise recursive + memoization solution
'''
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        result: bool=False

        valid_positions: Set[int]=set(stones)

        memo: Dict[Tuple[int, int], int]=dict()

        last_stone: int=stones[-1]

        position: int=0

        k: int=0

        result=self.solve(stones, memo, valid_positions, last_stone, position, k)

        return result
    
    def solve(self, stones: List[int], memo: Dict[Tuple[int, int], int], valid_positions: Set[int], last_stone: int, position: int, k: int) -> bool:
        if position not in valid_positions:
            return False

        if position==last_stone:
            return True

        key: Tuple[int, int]=(position, k)

        if key in memo.keys():
            return memo[key]

        subproblem_solution: bool=False

        for next_jump in range(k-1, k+2):
            if next_jump > 0:
                subproblem_solution=subproblem_solution or self.solve(stones, memo, valid_positions, last_stone, position + next_jump, next_jump)

        memo[key]=subproblem_solution

        return subproblem_solution
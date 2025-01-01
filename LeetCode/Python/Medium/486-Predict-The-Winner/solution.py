class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n: int=len(nums)

        total: int=sum(nums)

        left: int=0

        right: int=n - 1

        player1_score: int=self.get_player1_score(nums, left, right)

        player2_score: int=total - player1_score

        return player1_score >= player2_score

    def get_player1_score(self, nums: List[int], left: int, right: int) -> int:
        if left > right:
            return 0

        subproblem_solution: int=0

        #Player 1 picks a number from the left end of the array
        #Once this happens, player 2 has two options:
        #1) They can also pick a number from the left end of the array.
        #If they do this, then left needs to be incremented by two since player1 and player2 picked from the left end.
        #This results in the first recursive function call self.get_player1_score(nums, left + 2, right)
        
        #2) They can pick a number from the right end of the array.
        #If they do this, then left needs to be incremented to account for player 1's choice and right needs to be decremented to account for player 2's choice.
        #This results in the second recursive function call self.get_player1_score(nums, left + 1, right - 1)
        player1_picks_from_left_end: int=nums[left] + min(self.get_player1_score(nums, left + 2, right), self.get_player1_score(nums, left + 1, right - 1))

        
        #Player 1 picks a number from the right end of the array
        #Once this happens, player 2 has two options:
        #1) They can also pick a number from the right end of the array.
        #If they do this, then right needs to be decremented by two since player1 and player2 picked from the right end.
        #This results in the first recursive function call: self.get_player1_score(nums, left, right - 2)

        #2) They can pick a number from the left end of the array.
        #If they do this, then left needs to be incremented to account for player 2's choice and right needs to be decremented to account for player 1's choice.
        #This results in the second recursive function call: self.get_player1_score(nums, left + 1, right - 1).
        player1_picks_from_right_end: int=nums[right] + min(self.get_player1_score(nums, left, right - 2), self.get_player1_score(nums, left + 1, right - 1))

        subproblem_solution=max(player1_picks_from_left_end, player1_picks_from_right_end)

        return subproblem_solution

class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n: int=len(nums)

        total: int=sum(nums)

        left: int=0

        right: int=n - 1

        #memo: List[List[int]]=[[-1 for _ in range(0, n + 1)] for _ in range(0, n + 1)]

        memo: List[List[int]]=[[-1] * (n + 1) for _ in range(0, n + 1)]

        player1_score: int=self.get_player1_score(nums, memo, left, right)

        player2_score: int=total - player1_score

        return player1_score >= player2_score

    def get_player1_score(self, nums: List[int], memo: List[List[int]], left: int, right: int) -> int:
        if left > right:
            return 0

        if memo[left][right]!=-1:
            return memo[left][right]

        subproblem_solution: int=0

        player1_picks_from_left_end: int=nums[left] + min(self.get_player1_score(nums, memo, left + 2, right), self.get_player1_score(nums, memo, left + 1, right - 1))

        player1_picks_from_right_end: int=nums[right] + min(self.get_player1_score(nums, memo, left, right - 2), self.get_player1_score(nums, memo, left + 1, right - 1))

        subproblem_solution=max(player1_picks_from_left_end, player1_picks_from_right_end)

        memo[left][right]=subproblem_solution

        return subproblem_solution
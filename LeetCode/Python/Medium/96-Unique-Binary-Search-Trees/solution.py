'''
Solution 1: pure recursion.
Note: this solution will receive Time Limit Exceeded if submitted. DO NOT SUBMIT this solution!!!
I have only included it so you can see how the memoization solution is derived from the recursive solution.
'''
class Solution:
    def numTrees(self, n: int) -> int:
        result: int=0

        result=self.solve(n)

        return result

    def solve(self, n: int) -> int:
        #If there is one or less roots remaining, then there is only one way to form a binary search tree
        if n <= 1:
            return 1

        subproblem_solution: int=0

        #Loop through all possible roots
        for root in range(1, n + 1):
            #The number of possible left subtree roots
            left_subtree_roots: int=root - 1

            number_of_left_subtrees: int=self.solve(left_subtree_roots)

            #The number of possible right subtree roots
            right_subtree_roots: int=n - root

            number_of_right_subtrees: int=self.solve(right_subtree_roots)

            subproblem_solution+=(number_of_left_subtrees * number_of_right_subtrees)

        return subproblem_solution

'''
Solution 2: recursion + memoization. This solution is accepted by the online judge
'''
class Solution:
    def numTrees(self, n: int) -> int:
        result: int=0

        memo: List[int]=[-1] * (n + 1)

        result=self.solve(memo, n)

        return result

    def solve(self, memo: List[int], n: int) -> int:
        if n <= 1:
            return 1

        if memo[n]!=-1:
            return memo[n]

        subproblem_solution: int=0

        for root in range(1, n + 1):
            left_subtree_roots: int=root - 1

            number_of_left_subtrees: int=self.solve(memo, left_subtree_roots)

            right_subtree_roots: int=n - root

            number_of_right_subtrees: int=self.solve(memo, right_subtree_roots)

            subproblem_solution+=(number_of_left_subtrees * number_of_right_subtrees)

        memo[n]=subproblem_solution

        return subproblem_solution
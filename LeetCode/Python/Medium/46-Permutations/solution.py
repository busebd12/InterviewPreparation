import itertools

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]]=list()

        n: int=len(nums)

        permutation: List[int]=list()

        visited: List[bool]=[False] * n

        self.backtracking(nums, result, permutation, visited, n)

        return result

    def backtracking(self, nums: List[int], result: List[List[int]], permutation: List[int], visited: List[bool], n: int) -> None:
        if len(permutation)==n:
            result.append(permutation.copy())

            return

        for index in range(0, n):
            if not visited[index]:
                visited[index]=True

                permutation.append(nums[index])

                self.backtracking(nums, result, permutation, visited, n)

                permutation.pop()

                visited[index]=False

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]]=list()

        n: int=len(nums)

        permutations=list(itertools.permutations(nums, n))

        result=[permutation for permutation in permutations]

        return result
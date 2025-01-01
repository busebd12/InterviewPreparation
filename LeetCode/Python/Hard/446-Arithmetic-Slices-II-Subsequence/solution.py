'''
Solution 1: pure recursion. DO NOT submit this solution as it will get Time Limit Exceeded.
'''
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        result=0

        n=len(nums)

        hashmap=dict()

        for (index, number) in enumerate(nums):
            if number not in hashmap.keys():
                hashmap[number]=list()
            
            hashmap[number].append(index)

        for i in range(0, n):
            for j in range(i + 1, n):
                difference=nums[j] - nums[i]

                target=nums[j] + difference

                result+=self.helper(nums, hashmap, n, difference, target, j)

        return result

    def helper(self, nums: List[int], hashmap: Dict[int, List[int]], n: int, difference: int, target: int, index: int) -> int:
        if index==n:
            return 0

        if target not in hashmap.keys():
            return 0

        subproblem_solution=0

        for i in hashmap[target]:
            if i > index:
                next_target=nums[i] + difference

                subproblem_solution+=1 + self.helper(nums, hashmap, n, difference, next_target, i)

        return subproblem_solution

'''
Solution 2: recursion + memoization. This solution is accepted.
'''
class Solution:
    def __init__(self):
        self.memo=dict()

    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        result=0

        n=len(nums)

        hashmap=dict()

        for (index, number) in enumerate(nums):
            if number not in hashmap.keys():
                hashmap[number]=list()
            
            hashmap[number].append(index)

        for i in range(0, n):
            for j in range(i + 1, n):
                difference=nums[j] - nums[i]

                target=nums[j] + difference

                result+=self.helper(nums, hashmap, n, difference, target, j)

        return result

    def helper(self, nums: List[int], hashmap: Dict[int, List[int]], n: int, difference: int, target: int, index: int) -> int:
        if index==n:
            return 0

        if target not in hashmap.keys():
            return 0

        key=(target, index)

        if key in self.memo.keys():
            return self.memo[key]

        subproblem_solution=0

        for i in hashmap[target]:
            if i > index:
                next_target=nums[i] + difference

                subproblem_solution+=1 + self.helper(nums, hashmap, n, difference, next_target, i)

        self.memo[key]=subproblem_solution

        return subproblem_solution
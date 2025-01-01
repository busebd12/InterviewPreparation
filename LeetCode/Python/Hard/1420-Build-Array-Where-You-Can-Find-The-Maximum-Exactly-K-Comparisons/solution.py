'''
Solution 1: pure recursion
'''
class Solution:
    def __init__(self):
        self.MOD: int=(10**9) + 7

    def numOfArrays(self, n: int, m: int, k: int) -> int:
        result: int=0

        previous: int=-1

        result=self.helper(n, m, k, previous)

        return result

    def helper(self, n: int, m: int, k: int, previous: int) -> int:
        #If we've picked all n numbers for the array
        if n == 0:
            #If the array has a search_cost equal to k
            if k==0:
                #We've successfully built one possible array
                return 1
            #Else, the array doesn't have a search_cost equal to k
            else:
                #This array is not valid
                return 0

        ways: int=0

        #Loop through numbers [1, m] and choose each one to be a possible next value in the array
        for number in range(1, m + 1):
            #If the number is larger than the previous maximum
            if number > previous:
                #If we have room in the array for this number and the search_cost for the array has not reached k yet
                if n > 0 and k > 0:
                    #Pick the number (simulating adding it to the array), decrement the search_cost, and recurse
                    ways+=(self.helper(n - 1, m, k - 1, number) % self.MOD)
            #Else, number is less-than-or-equal to previous and we don't have to decrease our search_cost
            #However, we still pick the number (simulating adding it to the array)
            else:
                if n > 0:
                    ways+=(self.helper(n - 1, m, k, previous) % self.MOD)

        return ways % self.MOD

'''
Solution 2: recursion + memoization
'''
class Solution:
    def __init__(self):
        self.MOD: int=(10**9) + 7

        self.memo: List[List[List[int]]]=list()

    def numOfArrays(self, n: int, m: int, k: int) -> int:
        result: int=0

        self.memo=[[[-1 for _ in range(0, m + 1)] for _ in range(0, k + 1)] for _ in range(0, n + 1)]

        previous: int=-1

        result=self.helper(n, m, k, previous) % self.MOD

        return result

    def helper(self, n: int, m: int, k: int, previous: int) -> int:
        if n == 0:
            if k==0:
                return 1
            else:
                return 0

        if self.memo[n][k][previous]!=-1:
            return self.memo[n][k][previous]

        ways: int=0

        for number in range(1, m + 1):
            if number > previous:
                if n > 0 and k > 0:
                    ways+=(self.helper(n - 1, m, k - 1, number) % self.MOD)
            else:
                if n > 0:
                    ways+=(self.helper(n - 1, m, k, previous) % self.MOD)

        self.memo[n][k][previous]=(ways % self.MOD)

        return ways % self.MOD
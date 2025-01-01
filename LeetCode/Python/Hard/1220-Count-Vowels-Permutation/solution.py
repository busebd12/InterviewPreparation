'''
Solution 1: pure recursion.
IMPORTANT: do NOT submit this solution, it results in Time Limit Exceeded.
'''
class Solution:
    def __init__(self):
        self.MOD: int=(10**9) + 7

    def countVowelPermutation(self, n: int) -> int:
        result: int=0

        hashmap: Dict[chr, List[chr]]={'a':['e'], 'e':['a', 'i'], 'i':['a', 'e', 'o', 'u'], 'o':['i', 'u'], 'u':['a']}

        length: int=0

        previous_letter: chr='$'

        result=self.helper(hashmap, n, length, previous_letter)

        return result

    def helper(self, hashmap: Dict[chr, List[chr]], n: int, length: int, previous_letter: chr) -> int:
        if length==n:
            return 1

        subproblem_solution: int=0

        if length==0:
            for letter in hashmap.keys():
                subproblem_solution+=(self.helper(hashmap, n, length + 1, letter) % self.MOD)
        else:
            for next_letter in hashmap[previous_letter]:
                subproblem_solution+=(self.helper(hashmap, n, length + 1, next_letter) % self.MOD)

        subproblem_solution%=self.MOD

        return subproblem_solution
'''
Solution 2: recursion + memoization via hashamp
'''
class Solution:
    def __init__(self):
        self.MOD: int=(10**9) + 7

        self.memo: Dict[Tuple[int, chr], int]=dict()

    def countVowelPermutation(self, n: int) -> int:
        result: int=0

        hashmap: Dict[chr, List[chr]]={'a':['e'], 'e':['a', 'i'], 'i':['a', 'e', 'o', 'u'], 'o':['i', 'u'], 'u':['a']}

        length: int=0

        previous_letter: chr='$'

        result=self.helper(hashmap, n, length, previous_letter)

        return result

    def helper(self, hashmap: Dict[chr, List[chr]], n: int, length: int, previous_letter: chr) -> int:
        if length==n:
            return 1

        key: Tuple[int, chr]=(length, previous_letter)

        if key in self.memo.keys():
            return self.memo[key]

        subproblem_solution: int=0

        if length==0:
            for letter in hashmap.keys():
                subproblem_solution+=(self.helper(hashmap, n, length + 1, letter) % self.MOD)
        else:
            for next_letter in hashmap[previous_letter]:
                subproblem_solution+=(self.helper(hashmap, n, length + 1, next_letter) % self.MOD)

        subproblem_solution%=self.MOD

        self.memo[key]=subproblem_solution

        return subproblem_solution

'''
Solution 3: recursion + memoization via a 2D array
'''
class Solution:
    def __init__(self):
        self.MOD: int=(10**9) + 7

        self.memo: List[List[int]]=list()

    def countVowelPermutation(self, n: int) -> int:
        result: int=0

        self.memo=[[-1 for _ in range(26)] for _ in range(0, n + 1)]

        hashmap: Dict[chr, List[chr]]={'a':['e'], 'e':['a', 'i'], 'i':['a', 'e', 'o', 'u'], 'o':['i', 'u'], 'u':['a']}

        length: int=0

        previous_letter: chr='$'

        result=self.helper(hashmap, n, length, previous_letter)

        return result

    def helper(self, hashmap: Dict[chr, List[chr]], n: int, length: int, previous_letter: chr) -> int:
        if length==n:
            return 1

        ascii_index: int=ord(previous_letter) - ord('a')

        if previous_letter!='$' and self.memo[length][ascii_index]!=-1:
            return self.memo[length][ascii_index]

        subproblem_solution: int=0

        if length==0:
            for letter in hashmap.keys():
                subproblem_solution+=(self.helper(hashmap, n, length + 1, letter) % self.MOD)
        else:
            for next_letter in hashmap[previous_letter]:
                subproblem_solution+=(self.helper(hashmap, n, length + 1, next_letter) % self.MOD)

        subproblem_solution%=self.MOD

        if previous_letter!='$':
            self.memo[length][ascii_index]=subproblem_solution

        return subproblem_solution
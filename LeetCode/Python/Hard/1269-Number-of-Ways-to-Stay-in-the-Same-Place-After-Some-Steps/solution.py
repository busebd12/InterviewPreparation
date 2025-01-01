class Solution:
    def __init__(self):
        self.memo=dict()

        self.MOD=(10**9) + 7

    def numWays(self, steps: int, arrLen: int) -> int:
        result: int=0

        total: int=0

        moves: int=0

        index: int=0

        result=self.helper(arrLen, steps, total, moves, index)

        return result

    def helper(self, arrLen: int, steps: int, total: int, moves: int, index: int) -> int:
        if moves==steps:
            if total==0:
                return 1
            else:
                return 0

        key: Tuple[int, int, int]=(total, moves, index)

        if key in self.memo.keys():
            return self.memo[key]

        ways: int=0

        for offset in range(-1, 2, 1):
            if offset==1 and index + 1 > arrLen - 1:
                continue

            if offset==-1 and index - 1 < 0:
                continue

            total+=offset

            moves+=1

            index+=offset

            ways+=(self.helper(arrLen, steps, total, moves, index) % self.MOD)

            index-=offset

            moves-=1

            total-=offset

        self.memo[key]=(ways % self.MOD)

        return ways % self.MOD
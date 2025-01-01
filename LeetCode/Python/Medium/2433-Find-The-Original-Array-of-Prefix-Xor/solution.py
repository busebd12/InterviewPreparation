class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        result: List[int]=list()

        n: int=len(pref)

        result.append(pref[0])

        for index in range(0, n - 1):
            result.append(pref[index] ^ pref[index + 1])

        return result
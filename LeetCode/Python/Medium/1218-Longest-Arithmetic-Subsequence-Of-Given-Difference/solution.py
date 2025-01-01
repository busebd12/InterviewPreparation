class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        result: int=0

        hashmap: dict[int, int]=dict()

        for number in arr:
            number_before_current_in_sequence: int=number - difference

            if number_before_current_in_sequence in hashmap:
                hashmap[number]=hashmap.get(number_before_current_in_sequence) + 1
            else:
                hashmap[number]=1

        for length in hashmap.values():
            result=max(result, length)

        return result
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        result: int=0

        left_index: List[int]=[-1 for _ in range(0, 27)]

        right_index: List[int]=[-1 for _ in range(0, 27)]

        for (index, letter) in enumerate(s):
            ascii_value: int=ord(letter) - ord('a')
            
            if left_index[ascii_value]==-1:
                left_index[ascii_value]=index
            elif right_index[ascii_value]==-1:
                right_index[ascii_value]=index
            else:
                right_index[ascii_value]=max(right_index[ascii_value], index)

        for ascii_value in range(0, 26):
            if left_index[ascii_value]!=-1 and right_index[ascii_value]!=-1:

                middle_letters: Set[chr]=set(s[left_index[ascii_value] + 1 : right_index[ascii_value]])

                result+=len(middle_letters)

        return result
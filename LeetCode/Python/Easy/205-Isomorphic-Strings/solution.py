class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_hashmap: dict[chr, chr]=dict()

        for s_letter, t_letter in zip(s, t):
            if s_letter not in s_hashmap:
                s_hashmap[s_letter]=t_letter
            else:
                if s_hashmap[s_letter]!=t_letter:
                    return False

        t_hashmap: dict[chr, chr]=dict()

        for s_letter, t_letter in zip(s, t):
            if t_letter not in t_hashmap:
                t_hashmap[t_letter]=s_letter
            else:
                if t_hashmap[t_letter]!=s_letter:
                    return False
        
        return True

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_hashmap: list[int]=[-1] * 256

        for s_letter, t_letter in zip(s, t):
            s_letter_ascii: int=ord(s_letter)

            t_letter_ascii: int=ord(t_letter)
            
            if s_hashmap[s_letter_ascii]==-1:
                s_hashmap[s_letter_ascii]=t_letter_ascii
            else:
                if s_hashmap[s_letter_ascii]!=t_letter_ascii:
                    return False

        t_hashmap: list[int]=[-1] * 256

        for s_letter, t_letter in zip(s, t):
            s_letter_ascii: int=ord(s_letter)

            t_letter_ascii: int=ord(t_letter)
            
            if t_hashmap[t_letter_ascii]==-1:
                t_hashmap[t_letter_ascii]=s_letter_ascii
            else:
                if t_hashmap[t_letter_ascii]!=s_letter_ascii:
                    return False
        
        return True
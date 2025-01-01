from bisect import bisect_right

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        previous_letter_index: int=-1

        hashmap: Dict[chr, List[int]]=dict()

        for (index, letter) in enumerate(t):
            if letter not in hashmap.keys():
                hashmap[letter]=list()
            
            hashmap[letter].append(index)

        for letter in s:
            if letter not in hashmap.keys():
                return False

            current_letter_index=self.get_current_letter_index(hashmap[letter], previous_letter_index)

            if current_letter_index==None:
                return False

            previous_letter_index=current_letter_index

        return True

    def get_current_letter_index(self, sorted_indices: List[int], previous_letter_index) -> Any:
        index: int=bisect_right(sorted_indices, previous_letter_index)

        if index >= len(sorted_indices):
            return None

        return sorted_indices[index]
    
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n: int=len(s)
        
        m: int=len(t)

        i: int=0

        j: int=0

        while j < m:
            if i < n and s[i]==t[j]:
                i+=1
            
            j+=1

        return i==n
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_hashmap: Dict[chr, int]=self.build_hashmap(magazine)

        ransom_note_hashmap: Dict[chr, int]=self.build_hashmap(ransomNote)

        for letter in ransomNote:
            if letter not in magazine_hashmap.keys() or magazine_hashmap[letter] < ransom_note_hashmap[letter]:
                return False
        
        return True

    def build_hashmap(self, string: str) -> Dict[chr, int]:
        hashmap: Dict[chr, int]=dict()

        for letter in string:
            if letter not in hashmap.keys():
                hashmap[letter]=1
            else:
                hashmap[letter]+=1

        return hashmap
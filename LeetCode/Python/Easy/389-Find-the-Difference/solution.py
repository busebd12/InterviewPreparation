class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        result: chr=''

        if not s:
            result=t

            return result

        s_hashmap: Dict[chr, int]=self.populate_hashmap(s)

        t_hashmap: Dict[chr, int]=self.populate_hashmap(t)

        for (letter, frequency) in t_hashmap.items():
            if letter not in s_hashmap.keys() or frequency==(s_hashmap[letter] + 1):
                result=letter

                break

        return result

    def populate_hashmap(self, string: str) -> Dict[chr, int]:
        hashmap: Dict[chr, int]=dict()

        for letter in string:
            if letter not in hashmap.keys():
                hashmap[letter]=1
            else:
                hashmap[letter]+=1

        return hashmap
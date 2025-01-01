class Solution:
    def firstUniqChar(self, s: str) -> int:
        result: int=-1

        n: int=len(s)

        hashmap: list[list[bool, int]]=[[False, -1] for _ in range(0, 123)]

        for index in range(0, n):
            letter: chr=s[index]

            ascii: int=ord(letter)

            if hashmap[ascii][0]==False:
                if hashmap[ascii][1]==-1:
                    hashmap[ascii][1]=index
                else:
                    hashmap[ascii][0]=True

                    hashmap[ascii][1]=index
            else:
                hashmap[ascii][1]=index

        for index in range(0, n):
            letter: chr=s[index]

            ascii: int=ord(letter)

            if hashmap[ascii][0]==False and hashmap[ascii][1]!=-1:
                result=hashmap[ascii][1]

                break

        return result
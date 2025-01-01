class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        substring=""

        n=len(s)

        hashmap=dict()

        k=2

        left=0

        max_length=0

        substring_start=-1

        substring_end=-1

        for right in range(0, n):
            letter=s[right]

            if letter not in hashmap.keys():
                hashmap[letter]=1
            else:
                hashmap[letter]+=1

            if len(hashmap) <= k:
                substring_length=(right - left) + 1

                if substring_length > max_length:
                    max_length=substring_length

                    substring_start=left

                    substring_end=right
            else:
                while left < right and len(hashmap) > k:
                    if s[left] in hashmap:
                        hashmap[s[left]]-=1

                        if hashmap[s[left]]==0:
                            del hashmap[s[left]]

                    left+=1

        if substring_start!=-1 and substring_end!=-1:
            substring=s[substring_start : substring_end + 1]

        #print(substring)

        return max_length

class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        substring=""

        n=len(s)

        hashmap=[0 for _ in range(0, 123)]

        k=2

        left=0

        max_length=0

        substring_start=-1

        substring_end=-1

        for right in range(0, n):
            letter=s[right]

            ascii=ord(letter)

            hashmap[ascii]+=1

            while left < right and self.get_number_of_unique_letters(hashmap) > k:
                left_index=ord(s[left])
                
                if hashmap[left_index] > 0:
                    hashmap[left_index]-=1

                left+=1

            substring_length=(right - left) + 1

            if substring_length > max_length:
                max_length=substring_length

                substring_start=left

                substring_end=right

        if substring_start!=-1 and substring_end!=-1:
            substring=s[substring_start : substring_end + 1]

        #print(substring)

        return max_length

    def get_number_of_unique_letters(self, hashmap: List[int]) -> int:
        unique_letters=0

        for index in range(0, 123):
            if hashmap[index] > 0:
                unique_letters+=1

        return unique_letters
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        result=""

        n=len(s)

        m=len(t)

        if n < m:
            return result

        t_frequencies=dict()

        for character in t:
            if character not in t_frequencies.keys():
                t_frequencies[character]=0
            
            t_frequencies[character]+=1

        hashmap=dict()

        left=0

        right=0

        min_length=-1

        substring_start=-1

        substring_end=-1

        unique_t_characters_found=0

        required=len(t_frequencies)

        while right < n:
            character=s[right]

            if character not in hashmap.keys():
                hashmap[character]=0

            hashmap[character]+=1

            if character in t_frequencies.keys() and hashmap[character]==t_frequencies[character]:
                unique_t_characters_found+=1

            while left <= right and unique_t_characters_found==required:
                length=(right - left) + 1

                if min_length==-1 or length < min_length:
                    min_length=length

                    substring_start=left

                    substring_end=right

                left_character=s[left]

                hashmap[left_character]-=1

                if left_character in t_frequencies.keys() and hashmap[left_character] < t_frequencies[left_character]:
                    unique_t_characters_found-=1

                left+=1

            right+=1

        if min_length!=-1 and substring_start!=-1 and substring_end!=-1:
            end=substring_start + min_length

            result=s[substring_start : end]

        return result
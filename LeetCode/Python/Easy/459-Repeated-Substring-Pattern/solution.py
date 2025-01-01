
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n: int=len(s)

        half: int=n // 2

        #Iterate through substring lengths [1, half of original string] because the largest possible
        #substring that we can concatenate at least once with itself is half of the original string
        for substring_length in range(1, half + 1):
            substring: str=s[0 : substring_length]

            #If the length of the substring is a multiple of the length of the original string
            if n % len(substring) == 0:
                #Calculate the total number of substring concatenations we need to do
                number_of_substrings: int=n // len(substring)

                match: str=""

                #Do the concatenations
                for count in range(0, number_of_substrings):
                    match+=substring

                #If the concatenations result in the original string
                if match==s:
                    return True

        return False
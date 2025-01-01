class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        result: int=0

        if k==0:
            return result

        n: int=len(s)

        hashmap: list[int]=[0] * 128

        left: int=0

        right: int=0

        distinct: int=0

        while right < n:
            right_letter: chr=s[right]

            right_ascii: int=ord(right_letter)

            #If this is the first occurrence of the chracter
            if hashmap[right_ascii]==0:
                #Assign initial frequency
                hashmap[right_ascii]=1

                #Increment the number of distinct characters
                distinct+=1
            else:
                #Just increment the frequency
                hashmap[right_ascii]+=1

            #At this point, if the current window has more than k distinct characters, then we need to shrink the window from the left
            while left < right and distinct > k:
                left_letter: chr=s[left]

                left_ascii: int=ord(left_letter)

                #If the frequency of s[left] is greater than zero
                if hashmap[left_ascii] > 0:
                    hashmap[left_ascii]-=1

                    #If the frequency is zero, then this character is no longer in the current window and the number of distinct characters decreases by one
                    if hashmap[left_ascii]==0:
                        distinct-=1

                #Move the left pointer
                left+=1

            #At this point, the current window has at most k distinct characters so calculate its length
            length: int=(right - left) + 1

            #Update the result
            result=max(result, length)

            #Move the right pointer
            right+=1

        return result
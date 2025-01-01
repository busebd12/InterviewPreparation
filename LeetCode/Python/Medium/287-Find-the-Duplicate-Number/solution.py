class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        result: int=0

        seen: int=0

        for number in nums:
            #Get the bit in seen at the number-th position from the left
            bit_representing_number_in_seen: int=((seen >> number) & 1)

            #Check if the bit in seen at the number-th position from the left is 1
            already_seen_number: bool=(bit_representing_number_in_seen==1)

            #If so, we already seen the number and it is the duplicate
            if already_seen_number:
                result=number

                break
            #Else, set the bit in seen at the number-th position from the left to 1 to indicate that we've seen the number already
            else:
                seen=(seen | (1 << number))

        return result
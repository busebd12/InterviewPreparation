
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result: int=0

        hashmap: dict[int, int]=dict()

        for number in nums:
            if number not in hashmap:
                hashmap[number]=0

            hashmap[number]+=1

        for key, value in hashmap.items():
            if value==1:
                result=key

                break

        return result

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        k: int=3

        #Count the number of negatives values in nums
        negatives: int=sum(number < 0 for number in nums)

        sign: int=0

        #If the number of negative values in nums is not evenly divisible by k, then the single number will be negative and the sign will be -1
        if negatives % k == 1:
            sign=-1
        else:
            sign=1

        #Iterate over all 32 bit positions in an integer value
        for bit_position in range(0, 32):
            
            #The total number of bits in the bit_position position that are 1s from all numbers in nums
            set_bits: int=0

            for number in nums:
                
                #Check to see if the bit in position bit_position is a 1 or a 0 for the current number
                #Note: we take the absolute value of the number to account for negative values
                bit: int=(abs(number) >> bit_position) & 1

                if bit==1:
                    set_bits+=1

            #Here, we are modding set_bits by k to check if the total number of 1 bits in the bit_position position is evenly divisible by k.
            #If so, this means that all the numbers that had a 1 bit at the bit_position position appeared k times
            #If not, that means that there was a number that had a 1 bit in the bit_position position that appeared only one time, not k times
            set_bits%=k

            #Set the bit at position bit_position in result to be the value of set_bits
            #The bit value of position bit_position in result will match the bit value of the bit at bit_position in the single number
            result=result | (set_bits << bit_position)

        #Remember to multiply result by the sign we determined earlier to account for the single number in the array being negative
        result=result * sign

        return result
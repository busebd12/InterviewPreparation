class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result: int=0

        k: int=2

        #Count the number of negative values in the array
        negatives: int=sum(number < 0 for number in nums)

        sign: int=1

        #If the amount of negative values is not evenly divisible by k, then the single number will be negative
        if (negatives % k)==1:
            sign=-1

        #Iterate through all possible 32 bit positions in an integer
        for bit_position in range(0, 32):
            #Track the total number of set bits
            set_bits: int=0

            #Iterate through each number
            for number in nums:
                if number < 0:
                    number=abs(number)

                #Get the bit set in the bit_position position
                bit: int=(number >> bit_position) & 1

                #If the bit is a one
                if bit==1:
                    set_bits+=1

            #Here, we are modding set_bits by k to check if the total number of 1 bits in the bit_position position is evenly divisible by k.
            #If so, this means that all the numbers that had a 1 bit at the bit_position position appeared k times
            #If not, that means that there was a number that had a 1 bit in the bit_position position that appeared only one time, not k times
            set_bits%=k

            #Set the bit at position bit_position in result to be the value of set_bits
            #The bit value of position bit_position in result will match the bit value of the bit at bit_position in the single number
            result=result | (set_bits << bit_position)

        #Don't forget to multiply the result by the appropriate sign
        result=result * sign

        return result
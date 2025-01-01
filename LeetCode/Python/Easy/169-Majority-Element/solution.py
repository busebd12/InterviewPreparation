class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        majority: int=(n // 2) + 1

        #Assume that the sign of the majority element is positive
        sign: int=1

        #Iterate through all 32 possible bit positions in an integer
        for bit_position in range(0, 32):
            
            #Keep track of the total number of 1 bits in each position
            set_bits: int=0

            #For each number
            for number in nums:
                
                #Get the bit in position bit_position
                #We take the absolute value of each number to make each number positive
                bit=(abs(number) >> bit_position) & 1

                #If the bit in position bit_position is a 1
                if bit==1:
                    set_bits+=1

            #If the total number of set_bits in position bit_position is at least majority
            if set_bits >= majority:
                
                #If the number is negative, then the majority element will also be negative
                if number < 0:
                    sign=-1
                
                #Set the bit in position bit_position to 1 since the majority element will have a 1 in the bit position bit_position
                result=result | (1 << bit_position)

        #Multiply the majority element by the sign in-case it is negative
        result*=sign

        return result

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        majority: int=(n // 2) + 1

        hashmap: dict[int, int]=dict()

        for number in nums:
            if number not in hashmap:
                hashmap[number]=0
            
            hashmap[number]+=1

        for number, frequency in hashmap.items():
            if frequency >= majority:
                result=number

                break

        return result
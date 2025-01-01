class Solution:
    def numberOfWays(self, corridor: str) -> int:
        result: int=0

        seats: int=0

        for character in corridor:
            if character=='S':
                seats+=1

        if seats % 2 == 1 or not seats:
            return 0

        MOD: int=(10**9) + 7

        seats=0

        plants: int=0
        
        result=1

        for character in corridor:
            #If we found a seat
            if character=='S':
                seats+=1
            
            #If we've already found two seats and we find a plant
            if seats==2 and character=='P':
                plants+=1

            #If we've found three seats, then let's calculate how many ways we can place dividers between the two groups of seats
            if seats==3:
                seats=1

                #If there are k plants between the two groups of seats, then there are k + 1 ways to place the dividers
                result=(result * (plants + 1))

                plants=0

        return result % MOD
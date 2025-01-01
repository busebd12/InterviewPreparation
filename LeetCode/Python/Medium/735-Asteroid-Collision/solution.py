class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result: list[int]=list()

        for asteroid in asteroids:
            #If the stack is empty, just add the asteroid
            if not result:
                result.append(asteroid)
            #Else, stack is not empty and there are some asteroids in it
            else:
                #If the current asteroid is moving to the left
                if asteroid < 0:
                    #while the stack is not empty, the asteroid at the top of the stack is moving to the right,
                    #and the asteroid moving to the left is larger than the asteroid moving to the right
                    while result and result[-1] > 0 and abs(asteroid) > result[-1]:
                        #Remove the asteroid from the top of the stack
                        result.pop()

                    #If the stack is not empty
                    if result:
                        #If the asteroid at the top of the stack is moving to the right,
                        #then it has to be greater than or equal to the size of the current asteroid
                        if result[-1] > 0:
                            #If the sizes of the two asteroids are the same, then they cancel each other out
                            if result[-1]==abs(asteroid):
                                result.pop()
                        #Else, the asteroid moving to the right is larger than the asteroid moving to the left
                        else:
                            result.append(asteroid)
                    #Else, the stack is empty
                    else:
                        result.append(asteroid)
                #Else, the asteroid is moving to the right and will never collide with
                #the asteroid at the top of the stack, so just add it to the stack        
                else:
                    result.append(asteroid)

        return result
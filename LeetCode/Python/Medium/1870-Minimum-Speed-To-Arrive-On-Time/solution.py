class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        result: int=-1

        n: int=len(dist)

        low: int=1

        high: int=pow(10, 9)

        while low <= high:
            speed: int=(low + (high - low)//2)

            #If we can arrive on time by using the speed "speed"
            if self.can_arrive_on_time(dist, n, hour, speed):
                #Update the result
                result=speed

                #Try with a slower speed next time since we want to find the minimum possible speed
                high=speed - 1
            #Else, the current speed is to slow, so let's try with a faster speed next time
            else:
                low=speed + 1

        return result

    
    def can_arrive_on_time(self, dist: List[int], n: int, hour: float, speed: int) -> bool:
        travel_time: float=0

        for index in range(0, n):
            if index < n-1:
                #Use the ceil function to account for any time spent waiting for the next train if the result of dist[index] / speed is not an integer
                travel_time+=ceil(dist[index] / speed)
            else:
                #Don't use the ceil function for the train since there are no more trains to potentially wait for after this one
                travel_time+=(dist[n - 1] / speed)

            #If the time it takes us to travel to the office will make us arrive after we are supposed to
            if travel_time > hour:
                return False

        return True
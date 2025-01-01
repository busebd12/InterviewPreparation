class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        result: int=0

        b: int=len(batteries)

        total_battery_power: int=sum(batteries)

        low: int=0

        high: int=total_battery_power // n

        while low <= high:
            consecutive_minutes=(low + (high - low)//2)

            #If we can run the n computers for consecutive_minutes minutes,
            #then we need to try a larger amount of minutes since we want the maximum number of minutes
            if self.can_run_for(batteries, n, consecutive_minutes):
                result=consecutive_minutes

                low=consecutive_minutes + 1
            #If we can't run the n computers for consecutive_minutes minutes, then we need to try a smaller number of minutes
            else:
                high=consecutive_minutes - 1

        return result

    def can_run_for(self, batteries: List[int], n: int, consecutive_minutes: int) -> bool:
        #The battery power needed to run n computers for consecutive_minutes minutes
        battery_power_needed: int=consecutive_minutes * n

        battery_power: int=0

        for battery in batteries:
            #We take the minimum here because if the batter power is larger than consecutive_minutes, then we want the minimum of the two.
            #If the batter power is less than or equal to consecutive_minutes, then we just use all the battery's power
            power: int=min(battery, consecutive_minutes)

            battery_power+=power

        #We can only power the computers for consecutive_minutes if our total battery power is at least equal to the power we need
        return battery_power >= battery_power_needed
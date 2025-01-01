class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        result: int=0

        #Stores the maximum distance to the right that each tap can spray water
        max_distance_reached_from_tap: List[int]=[-1] * (n + 1)

        for index in range(0, n + 1):
            left: int=max(0, index - ranges[index])

            right: int=index + ranges[index]

            distance: int=right - left

            max_distance_reached_from_tap[left]=max(max_distance_reached_from_tap[left], distance)

        #If the water from tap 0 can reach the end of the garden
        if max_distance_reached_from_tap[0]==n:
            result=1

            return result

        result=1

        current_tap: int=0
        
        farthest_point_to_the_right_current_tap_can_water: int=current_tap + max_distance_reached_from_tap[current_tap]

        #We will now find minimum amount of largest intervals
        #in the garden to water such that the entire garden
        #is watered and there are no gaps between the intervals
        #Note: intervals can be consecutive and/or overlapping
        while farthest_point_to_the_right_current_tap_can_water < n:
            farthest_tap_reached_from_current_interval: int=farthest_point_to_the_right_current_tap_can_water

            #Iterate through all other taps, besides the current one, in the current section of the garden that is being watered
            for tap in range(current_tap + 1, farthest_point_to_the_right_current_tap_can_water + 1):
                #Compare the farthest distance with the distance to the right the current tap can spray water to find the
                #farthest distance to the right any of the taps in the currently watered section of the garden can reach
                farthest_tap_reached_from_current_interval=max(farthest_tap_reached_from_current_interval, tap + max_distance_reached_from_tap[tap])

            #If the farthest distance to the right any taps within the interval of the garden that is being watered isequal to the farthest distance
            #the current_tap tap can spray water to the right, then we cannot water any other sections of the garden besides the current one
            if farthest_tap_reached_from_current_interval==farthest_point_to_the_right_current_tap_can_water:
                return -1

            #Update the current_tap tap to be the furthest point any of the taps within the interval of the garden currently being watered
            current_tap=farthest_point_to_the_right_current_tap_can_water

            #Update the furthest point to the right the current tap can water to be the farthest tap reached by any
            #of the taps, excluding current_tap, within the interval of the garden that is currently being watered 
            farthest_point_to_the_right_current_tap_can_water=farthest_tap_reached_from_current_interval

            result+=1

        return result
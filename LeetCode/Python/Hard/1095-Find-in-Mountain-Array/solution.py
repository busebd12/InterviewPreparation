class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        peak_index: int=self.find_peak_index(mountain_arr)

        if peak_index==-1:
            return -1

        left_half_index: int=self.search_for_target_in_left_half(mountain_arr, target, peak_index)

        right_half_index: int=self.search_for_target_in_right_half(mountain_arr, target, peak_index)

        if left_half_index==-1 and right_half_index==-1:
            return -1

        if (left_half_index!=-1 and right_half_index==-1) or (left_half_index!=-1 and right_half_index!=-1):
            return left_half_index
        else:
            return right_half_index

    def find_peak_index(self, mountain_arr: 'MountainArray') -> int:
        n: int=mountain_arr.length()

        low: int=0

        high: int=n - 1

        while low <= high:
            middle: int=(low + (high - low)//2)

            if 0 < middle and middle < n-1:
                left_value: int=mountain_arr.get(middle - 1)

                middle_value: int=mountain_arr.get(middle)

                right_value: int=mountain_arr.get(middle + 1)

                if left_value < middle_value and middle_value > right_value:
                    return middle
                elif left_value < middle_value and middle_value < right_value:
                    low=middle + 1
                elif left_value > middle_value and middle_value > right_value:
                    high=middle - 1
            elif middle==0:
                low=middle + 1
            else:
                high=middle + 1
        
        return -1

    def search_for_target_in_left_half(self, mountain_arr: 'MountainArray', target: int, peak_index: int) -> int:
        low: int=0

        high: int=peak_index

        while low <= high:
            middle=(low + (high - low)//2)

            middle_value: int=mountain_arr.get(middle)
            
            if middle_value >= target:
                if middle_value==target:
                    return middle
                
                high=middle - 1
            else:
                low=middle + 1

        return -1

    def search_for_target_in_right_half(self, mountain_arr: 'MountainArray', target: int, peak_index: int) -> int:
        low=peak_index

        high=mountain_arr.length() - 1

        while low <= high:
            middle=(low + (high - low)//2)

            middle_value: int=mountain_arr.get(middle)
            
            if middle_value >= target:
                if middle_value==target:
                    return middle
                
                low=middle + 1
            else:
                high=middle - 1

        return -1
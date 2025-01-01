class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        smallest, smallest_index=min((array[0], index) for index, array in enumerate(arrays))

        largest, largest_index=max((array[-1], index) for index, array in enumerate(arrays))
        
        if largest_index!=smallest_index:
            return largest - smallest
        
        second_smallest, second_smallest_index=min((array[0], index) for index, array in enumerate(arrays) if index!=smallest_index)

        second_largest, second_largest_index=max((array[-1], index) for index, array in enumerate(arrays) if index!=largest_index)

        option1: int=largest - second_smallest

        option2: int=second_largest - smallest
        
        return max(option1, option2)
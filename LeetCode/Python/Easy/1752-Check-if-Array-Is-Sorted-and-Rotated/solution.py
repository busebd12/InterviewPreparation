class Solution:
    def check(self, nums: List[int]) -> bool:
        n: int=len(nums)
        
        sorted_nums: List[int]=sorted(nums)

        for rotations in range(0, n + 1):
            if self.is_rotated_k_positions(nums, sorted_nums, n, rotations):
                return True

        return False

    def is_rotated_k_positions(self, nums: List[int], sorted_nums: List[int], n: int, rotations: int) -> bool:
        for index in range(0, n):
            rotated_index: int=(index + rotations) % n

            if sorted_nums[index]!=nums[rotated_index]:
                return False

        return True

class Solution:
    def check(self, nums: List[int]) -> bool:
        n: int=len(nums)
        
        increase_to_decrease_switches: int=0

        for index in range(0, n - 1):
            if nums[index] > nums[index + 1]:
                increase_to_decrease_switches+=1

        if nums[n - 1] > nums[0]:
            increase_to_decrease_switches+=1

        return increase_to_decrease_switches <= 1
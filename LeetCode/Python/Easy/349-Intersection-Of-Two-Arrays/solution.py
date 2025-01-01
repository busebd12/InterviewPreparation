class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result: list[int]=list()

        intersection: set[int]=set()

        nums2_set: set[int]=set(nums2)

        for number in nums1:
            if number in nums2_set and number not in intersection:
                intersection.add(number)

        result=[number for number in intersection]

        return result
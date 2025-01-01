class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        merged_length: int=m + n

        merged: list[int]=[0] * merged_length

        merge_index: int=0

        nums1_index: int=0

        nums2_index: int=0

        while nums1_index < m or nums2_index < n or merge_index < merged_length:
            if nums1_index < m and nums2_index < n:
                if nums1[nums1_index] <= nums2[nums2_index]:
                    merged[merge_index]=nums1[nums1_index]

                    nums1_index+=1
                else:
                    merged[merge_index]=nums2[nums2_index]

                    nums2_index+=1

                merge_index+=1
            elif nums1_index < m:
                merged[merge_index]=nums1[nums1_index]

                nums1_index+=1

                merge_index+=1
            elif nums2_index < n:
                merged[merge_index]=nums2[nums2_index]

                nums2_index+=1

                merge_index+=1

        for index in range(0, merged_length):
            nums1[index]=merged[index]
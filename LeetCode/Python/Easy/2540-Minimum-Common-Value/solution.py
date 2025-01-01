class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        result=-1

        n=len(nums1)

        m=len(nums2)

        i=0

        j=0

        while i < n and j < m:
            if nums1[i] < nums2[j]:
                i+=1
            elif nums1[i] > nums2[j]:
                j+=1
            else:
                result=nums1[i]

                break

        return result
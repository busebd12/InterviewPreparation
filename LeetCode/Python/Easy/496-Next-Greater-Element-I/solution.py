class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result: List[int]=None

        n: int=len(nums1)

        m: int=len(nums2)

        result=[-1 for iteration in range(0, n)]

        max_value: int=10000

        hashmap: List[int]=[-1 for iteration in range(0, max_value + 1)]

        for index in range(0, m):
            number: int=nums2[index]

            hashmap[number]=index

        for i in range(0, n):
            number: int=nums1[i]

            j: int=hashmap[number]

            for index in range(j, m):
                if nums2[index] > number:
                    result[i]=nums2[index]

                    break

        return result
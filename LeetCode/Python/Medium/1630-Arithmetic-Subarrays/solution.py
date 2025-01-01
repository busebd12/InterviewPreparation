class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        result: List[bool]=None
        
        n: int=len(nums)

        m: int=len(l)

        result=[True for _ in range(0, m)]

        for index in range(0, m):
            left: int=l[index]

            right: int=r[index]

            subarray: List[int]=list()

            for i in range(left, right + 1):
                subarray.append(nums[i])

            subarray.sort()

            if len(subarray) > 2:
                difference: int=subarray[1] - subarray[0]

                for j in range(2, len(subarray)):
                    current_difference: int=subarray[j] - subarray[j - 1]

                    if current_difference!=difference:
                        result[index]=False

                        break

        return result
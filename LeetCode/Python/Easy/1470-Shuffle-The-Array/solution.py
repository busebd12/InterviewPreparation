class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result: list[int]=list()

        N: int=len(nums)

        left: int=0

        right: int=n

        while right < N:
            result.append(nums[left])

            result.append(nums[right])

            left+=1

            right+=1

        return result
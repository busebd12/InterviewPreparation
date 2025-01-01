class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result: List[int]=list()

        n: int=len(nums)

        hashmap: dict[int, int]=dict()

        for index in range(0, n):
            number: int=nums[index]

            if number in hashmap:
                result.append(hashmap[number])

                result.append(index)

                break
            else:
                difference: int=target - nums[index]
                
                hashmap[difference]=index

        return result
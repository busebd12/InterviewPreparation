class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n: int=len(nums)

        hashmap: Dict[int, int]=dict()

        for index in range(0, n):
            number: int=nums[index]

            if number in hashmap.keys():
                distance: int=index - hashmap[number]

                if distance <= k:
                    return True

            hashmap[number]=index

        return False

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n: int=len(nums)

        hashset: Set[int]=set()

        for index in range(0, n):
            number: int=nums[index]

            if len(hashset) > k:
                hashset.remove(nums[index - k - 1])

            if number in hashset:
                return True

            hashset.add(number)

        return False
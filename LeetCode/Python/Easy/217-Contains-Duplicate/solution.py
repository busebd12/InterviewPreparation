class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashmap: dict[int, int]=dict()

        for number in nums:
            if number not in hashmap:
                hashmap[number]=0

            hashmap[number]+=1

        all_distinct: bool=True

        for number, frequency in hashmap.items():
            if frequency > 1:
                all_distinct=False

        return all_distinct==False

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset: set(int)=set()

        for number in nums:
            if number not in hashset:
                hashset.add(number)
            else:
                return True

        return False

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        n: int=len(arr)

        hashmap: dict[int, int]=dict()

        for number in arr:
            if number not in hashmap:
                hashmap[number]=0

            hashmap[number]+=1

        frequencies: set[int]=set()

        for number, frequency in hashmap.items():
            if frequency not in frequencies:
                frequencies.add(frequency)
            else:
                return False

        return True

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        n: int=len(arr)

        hashmap: dict[int, int]=dict()

        for number in arr:
            if number not in hashmap:
                hashmap[number]=0

            hashmap[number]+=1

        max_frequency: int=1000

        buckets: int=max_frequency + 1

        frequencies: List[int]=[0] * buckets

        for number, frequency in hashmap.items():
            if frequencies[frequency]==0:
                frequencies[frequency]=1
            else:
                return False

        return True
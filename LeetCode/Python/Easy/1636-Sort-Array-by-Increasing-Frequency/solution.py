class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        result: List[int]=list()

        max_frequency: int=100

        buckets: List[List[int]]=[[] for _ in range(0, max_frequency + 1)]

        hashmap: Dict[int, int]=dict()

        for number in nums:
            if number not in hashmap.keys():
                hashmap[number]=1
            else:
                hashmap[number]+=1

        for number, frequency in hashmap.items():
            buckets[frequency].append(number)

        for frequency in range(1, max_frequency + 1):
            if buckets[frequency]:
                buckets[frequency].sort(reverse=True)

        for frequency in range(1, max_frequency + 1):
            if buckets[frequency]:
                for number in buckets[frequency]:
                    for count in range(0, frequency):
                        result.append(number)

        return result

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        result: List[int]=list()

        max_frequency: int=100

        buckets: List[Set[int]]=[set() for _ in range(0, max_frequency + 1)]

        hashmap: Dict[int, int]=dict()

        for number in nums:
            if number not in hashmap.keys():
                hashmap[number]=1
            else:
                hashmap[number]+=1

        for number, frequency in hashmap.items():
            buckets[frequency].add(number)

        min_value: int=-100

        max_value: int=100

        for frequency in range(1, max_frequency + 1):
            if buckets[frequency]:
                for number in range(max_value, min_value - 1, -1):
                    if number in buckets[frequency]:
                        for count in range(0, frequency):
                            result.append(number)

        return result
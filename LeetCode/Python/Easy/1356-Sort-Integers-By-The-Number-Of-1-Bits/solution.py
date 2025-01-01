class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        result: list[int]=list()

        total_bits: int=32

        buckets: list[list[int]]=[[] for _ in range(0, total_bits)]

        for number in arr:
            set_bits: int=self.get_number_of_set_bits(number)

            buckets[set_bits].append(number)

        for bucket in buckets:
            if len(bucket) > 0:
                bucket.sort()
                
                result.extend(bucket)

        return result

    def get_number_of_set_bits(self, number: int) -> int:
        set_bits: int=0

        while number > 0:
            bit: int=number & 1

            if bit==1:
                set_bits+=1
            
            number=number >> 1
        
        return set_bits

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=lambda element: (bin(element).count('1'), element))
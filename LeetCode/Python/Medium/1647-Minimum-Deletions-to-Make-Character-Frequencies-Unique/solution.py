class Solution:
    def minDeletions(self, s: str) -> int:
        result: int=0

        frequencies: List[int]=[0] * 26
        
        max_frequency: int=0

        for letter in s:
            ascii_value: int=ord(letter) - ord('a')

            frequencies[ascii_value]+=1
            
            max_frequency=max(max_frequency, frequencies[ascii_value])

        limit: int=pow(10, 5) + 1

        frequency_buckets: List[int]=[0] * limit

        for ascii_value in range(0, 26):
            frequency: int=frequencies[ascii_value]

            frequency_buckets[frequency]+=1
        
        for frequency in range(max_frequency, 0, -1):
            if frequency_buckets[frequency] > 1:
                letters_to_shift_down: int=frequency_buckets[frequency] - 1

                frequency_buckets[frequency - 1]+=letters_to_shift_down

                result+=letters_to_shift_down

        return result

class Solution:
    def minDeletions(self, s: str) -> int:
        result: int=0

        frequencies: List[int]=[0] * 26
        
        max_frequency: int=0

        for letter in s:
            ascii_value: int=ord(letter) - ord('a')

            frequencies[ascii_value]+=1
            
            max_frequency=max(max_frequency, frequencies[ascii_value])

        limit: int=max_frequency + 1

        frequency_buckets: List[int]=[0] * limit

        for ascii_value in range(0, 26):
            frequency: int=frequencies[ascii_value]

            frequency_buckets[frequency]+=1
        
        for frequency in range(max_frequency, 0, -1):
            if frequency_buckets[frequency] > 1:
                letters_to_shift_down: int=frequency_buckets[frequency] - 1

                frequency_buckets[frequency - 1]+=letters_to_shift_down

                result+=letters_to_shift_down

        return result
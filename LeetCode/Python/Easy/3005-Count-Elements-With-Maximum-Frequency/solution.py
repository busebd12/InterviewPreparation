from collections import Counter

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        result=0

        frequencies=Counter(nums)

        max_frequency=0

        for (number, frequency) in frequencies.items():
            max_frequency=max(max_frequency, frequency)

        for (number, frequency) in frequencies.items():
            if frequency==max_frequency:
                result+=frequency

        return result

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        result=0

        max_value=101

        frequencies=[0 for _ in range(0, max_value)]

        for number in nums:
            frequencies[number]+=1

        max_frequency=0

        for number in range(1, max_value):
            max_frequency=max(max_frequency, frequencies[number])

        for number in range(1, max_value):
            if frequencies[number]==max_frequency:
                result+=frequencies[number]

        return result
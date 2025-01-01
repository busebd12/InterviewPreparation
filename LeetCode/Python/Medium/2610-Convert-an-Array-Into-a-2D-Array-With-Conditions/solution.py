class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result=list()

        buckets=[0 for _ in range(0, 201)]

        max_frequency=0

        for number in nums:
            buckets[number]+=1

            max_frequency=max(max_frequency, buckets[number])

        result=[[] for _ in range(0, max_frequency)]

        ordered_frequencies=[[] for _ in range(0, max_frequency + 1)]

        for number in range(0, 201):
            frequency=buckets[number]

            if frequency > 0:
                ordered_frequencies[frequency].append(number)

        for frequency in range(max_frequency, 0, -1):
            if ordered_frequencies[frequency]:
                for number in ordered_frequencies[frequency]:
                    for iteration in range(0, frequency):
                        result[iteration].append(number)

        return result
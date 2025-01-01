class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        if n==1:
            return 1

        longest_increasing_subsequence_ending_here: List[int]=[1 for iteration in range(0, n)]

        number_of_longest_increasing_subsequences_ending_here: List[int]=[1  for iteration in range(0, n)]

        max_length: int=0

        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    if longest_increasing_subsequence_ending_here[j] + 1 > longest_increasing_subsequence_ending_here[i]:
                        longest_increasing_subsequence_ending_here[i]=longest_increasing_subsequence_ending_here[j] + 1

                        number_of_longest_increasing_subsequences_ending_here[i]=number_of_longest_increasing_subsequences_ending_here[j]

                    elif longest_increasing_subsequence_ending_here[j] + 1==longest_increasing_subsequence_ending_here[i]:
                        number_of_longest_increasing_subsequences_ending_here[i]+=number_of_longest_increasing_subsequences_ending_here[j]

            max_length=max(max_length, longest_increasing_subsequence_ending_here[i])

        for index in range(0, n):
            if longest_increasing_subsequence_ending_here[index]==max_length:
                result+=number_of_longest_increasing_subsequences_ending_here[index]

        return result
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        result=0

        n=len(nums)

        prefix_sums=[0 for _ in range(0, n)]

        prefix_sums[0]=-1 if nums[0]==0 else 1

        for index in range(1, n):
            if nums[index]==1:
                prefix_sums[index]=prefix_sums[index - 1] + 1
            else:
                prefix_sums[index]=prefix_sums[index - 1] - 1

        hashmap=dict()

        for (index, prefix_sum) in enumerate(prefix_sums):
            if prefix_sum not in hashmap.keys():
                if prefix_sum==0:
                    length=index + 1

                    result=max(result, length)
                else:
                    hashmap[prefix_sum]=index
            else:
                length=index - hashmap[prefix_sum]

                result=max(result, length)

        return result
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        result=0

        hashmap=dict()

        prefix_sum=0

        for number in nums:
            prefix_sum+=number

            if prefix_sum==k:
                result+=1

            previous_prefix_sum=prefix_sum - k

            if previous_prefix_sum in hashmap.keys():
                result+=hashmap[previous_prefix_sum]

            if prefix_sum not in hashmap.keys():
                hashmap[prefix_sum]=0

            hashmap[prefix_sum]+=1

        return result
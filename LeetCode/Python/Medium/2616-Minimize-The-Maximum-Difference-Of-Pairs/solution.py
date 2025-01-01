class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        result: int=0

        n: int=len(nums)

        nums.sort()

        low: int=0

        high: int=nums[-1] - nums[0]

        while low <= high:
            difference: int=(low + (high - low)//2)
            
            #If there are at least p pairs with difference "difference"
            if self.there_are_at_least_p_pairs(nums, n, p, difference):
                #Update the result
                result=difference

                #Set high to difference - 1 in the hopes of finding a smaller difference in the next round of binary search
                high=difference - 1
            #Else, there are not at least p pairs with difference "difference", so try to find a larger difference next time
            else:
                low=difference + 1
        
        return result

    def there_are_at_least_p_pairs(self, nums: List[int], n: int, p: int, difference: int) -> bool:
        pairs: int=0

        index: int=1

        while index < n:
            diff: int=nums[index] - nums[index - 1]

            #If the difference of the pair is less than or equal to the target difference
            if diff <= difference:
                pairs+=1

                #Increment index by two since we don't want to consider the right most number in the
                #pair as part of another pair because no index can be included in more than one pair
                index+=2
            else:
                #Only increment index by one since we want to consider this index in another possible pair
                index+=1

        return pairs >= p
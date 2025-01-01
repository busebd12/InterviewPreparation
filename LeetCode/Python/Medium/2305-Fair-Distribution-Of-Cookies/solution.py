import math

class Solution:
    result=None

    def __init__(self):
        self.result=pow(2, 53) - 1
    
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n: int=len(cookies)

        #If n equals k, then each child only gets one bag of cookies
        #The maximum possible amount of cookies a child can get is therefore the bag of cookies with the maximum value
        if n==k:
            self.result=max(cookies)

            return self.result

        buckets: List[int]=[0] * k

        index: int=0

        self.helper(cookies, buckets, n, k, index)

        return self.result
    
    def helper(self, cookies: List[int], buckets: List[int], n: int, k: int, index: int) -> None:
        #if we run out of cookies to distribute, time to compute the unfairness
        if index >= n:
            #We want to minimize the unfairness
            #The unfairness is the maximum value in buckets
            self.result=min(self.result, max(buckets))

            return None

        #Pruning condition: if the maximum value in buckets in already greater than or equal to the result,
        #then there's no need to continue the recursion since this path won't produce a smaller answer than the one we already have
        elif max(buckets) >= self.result:
            return None

        #Iterate through each of the k buckets
        for person in range(0, k):
            #Put all the cookies from the cookies[index] bag into the current kid's bucket
            buckets[person]+=cookies[index]

            #Recurse for the next bag of cookies
            self.helper(cookies, buckets, n, k, index + 1)

            #Remove all the cookies from the cookies[index] bag from the current kid's bucket as part of the backtracking process
            buckets[person]-=cookies[index]
        
        return None
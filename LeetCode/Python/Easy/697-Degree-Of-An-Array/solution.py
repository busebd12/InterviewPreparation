class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        result: int=sys.maxsize

        n: int=len(nums)

        hashmap: dict[int, int]=self.populate_hashmap(nums)
        
        max_frequency: int=self.get_max_frequency(hashmap)

        frequencies: dict[int, int]=dict()

        left: int=0

        right: int=0

        #Do le sliding window algorithm
        while right < n:
            
            #If the number is not in the hashmap yet, set the initial frequency to 0
            if nums[right] not in frequencies:
                frequencies[nums[right]]=0

            #Increment the frequency
            frequencies[nums[right]]+=1

            #While the frequency of the current window is equal to the desired maximum frequency
            while self.get_max_subarray_frequency(frequencies)==max_frequency:
                
                #Calculate the length of the window
                length: int=(right - left) + 1

                #Update the result
                result=min(result, length)

                #Decrement the frequency of the number on the left end of the window
                if frequencies[nums[left]] > 0:
                    frequencies[nums[left]]-=1

                #Shrink the window from the left
                left+=1

            #Expand the window to the right
            right+=1

        return result

    def populate_hashmap(self, nums: list[int]) -> dict[int, int]:
        hashmap: dict[int, int]=dict()

        for number in nums:
            if number not in hashmap:
                hashmap[number]=0

            hashmap[number]+=1

        return hashmap

    def get_max_frequency(self, hashmap: dict[int, int]) -> int:
        max_frequency: int=0

        for frequency in hashmap.values():
            max_frequency=max(max_frequency, frequency)

        return max_frequency

    def get_max_subarray_frequency(self, frequencies: dict[int, int]) -> int:
        max_subarray_frequency: int=0

        for frequency in frequencies.values():
            max_subarray_frequency=max(max_subarray_frequency, frequency)

        return max_subarray_frequency

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        result: int=sys.maxsize

        n: int=len(nums)

        max_frequency: int=0

        hashmap: dict[int, list[int]]=dict()

        for index in range(0, n):
            number: int=nums[index]

            if number not in hashmap:
                #Value is a list comprised of the frequency of the number, the first index it appears in nums, and the last index it appears in nums
                value=[1, index, index]

                hashmap[number]=value
            else:
                
                #Increment the frequency
                hashmap[number][0]+=1

                #Update the last index it appears
                hashmap[number][2]=index

            #Calculate the frequency of the most occurring value in nums
            max_frequency=max(max_frequency, hashmap[number][0])

        #Iterate through all key, value pairs in the hashmap
        for key, value in hashmap.items():
            frequency: int=value[0]

            #If the frequency of the current number matches the max_frequency
            if frequency==max_frequency:
                #First index in nums this number appears at
                start: int=value[1]

                #Last index in nums this number appears at
                end: int=value[2]

                #Calculate the length of the subarray formed between the indices [start, end] inclusive
                length: int=(end - start) + 1

                #Update the result
                result=min(result, length)

        return result
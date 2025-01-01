class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n: int=len(nums)

        for index in range(n-1, -1, -1):
            if nums[index]==0:
                i: int=index

                j: int=i + 1

                while j < n and nums[j]!=0:
                    temp: int=nums[j]
                    
                    nums[j]=nums[i]

                    nums[i]=temp

                    i+=1

                    j+=1

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n: int=len(nums)

        zeros: int=0

        for index in range(0, n):
            if nums[index]==0:
                zeros+=1
            else:
                #Replace the value in the array "zeros" spots back with the nums[index]
                nums[index - zeros]=nums[index]

        last_index: int=n-1

        #Replace the last "zeros" number of values in the array with zeros
        for count in range(0, zeros):
            nums[last_index - count]=0
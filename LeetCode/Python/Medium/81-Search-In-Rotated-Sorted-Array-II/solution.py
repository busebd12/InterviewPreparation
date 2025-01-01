class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n=len(nums)

        left: int=0

        right: int=n - 1

        while left <= right:
            #Iterate through all duplicate numbers from the left
            while left < right and nums[left]==nums[left + 1]:
                left+=1

            #Iterate through all duplicate numbers from the right
            while right > left and nums[right]==nums[right - 1]:
                right-=1
            
            middle: int=(left + (right - left)//2)

            #Found the target
            if nums[middle]==target:
                return True
            else:
                #If nums[middle] is less than or equal to nums[right], then the right half of the array is sorted
                if nums[middle] <= nums[right]:
                    #If the target could be in the right half of the array
                    if (nums[middle] <= target and target < nums[right]) or (nums[middle] < target and target <= nums[right]):
                        left=middle + 1
                    #Else, the only option left is that the target could be in the left half of the array
                    else:
                        right=middle - 1
                #If nums[left] is less than or equal nums[middle], then the left half of the array is sorted
                elif nums[left] <= nums[middle]:
                    #If the target could be in the left half of the array
                    if (nums[left] <= target and target < nums[middle]) or (nums[middle] < target and target <= nums[right]):
                        right=middle - 1
                    #Else, the only option left is that the target could be in the right half of the array
                    else:
                        left=middle + 1
        return False
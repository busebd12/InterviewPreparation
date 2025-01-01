class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        result: int=0

        n: int=len(nums)

        previous: int=nums[-1]

        for index in range(n-2, -1, -1):
            current: int=nums[index]

            #If the current number is greater than the previous value in the array,
            #then we need to perform operations to split the number into a collection
            #of numbers which are all less than or equal to previous
            if current > previous_larger:
                #The total amount of numbers in the collection after performing all operations
                total_numbers_after_all_splits: int=current // previous

                #Take the mod in-case previous doesn't evenly divide current
                mod_result: int=current % previous

                #If previous doesn't evenly divide current
                if mod_result!=0:
                    #Then the remainder has to be added to the collection of numbers resulting from performing the splitting operations
                    total_numbers_after_all_splits+=1

                #Calculate the new value for previous
                previous=current // total_numbers_after_all_splits

                #The number of splitting operations will be equal to the total number of values in
                #the collection of numbers resulting from performing all the replacement operations
                operations: int=total_numbers_after_all_splits - 1

                #Add the number of operations to the result
                result+=operations
            #Else, current <= previous
            else:
                previous=current

        return result
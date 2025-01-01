class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        result: int=0

        MOD: int=(10**9) + 7

        hashmap: Dict[int, int]=dict()

        for (index, number) in enumerate(nums):
            current: int=number

            difference: int=number - self.reverse_number(current)

            nums[index]=difference

        for number in nums:
            if number not in hashmap.keys():
                hashmap[number]=0
            else:
                hashmap[number]+=1

                result+=(hashmap[number] % MOD)

        result=result % MOD

        return result

    def reverse_number(self, number: int) -> int:
        reversed_number: int=0

        while number > 0:
            digit: int=number % 10

            reversed_number=(reversed_number * 10) + digit

            number//=10

        return reversed_number
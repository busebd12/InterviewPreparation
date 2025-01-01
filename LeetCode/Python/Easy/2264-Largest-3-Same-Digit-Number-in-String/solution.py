class Solution:
    def largestGoodInteger(self, num: str) -> str:
        result: str=""

        frequencies: List[int]=[0 for _ in range(0, 11)]

        n: int=len(num)

        k: int=3

        i: int=0

        previous_digit: int=-1

        while i < n:
            number: int=int(num[i])

            frequencies[number]+=1

            left_index: int=i - (k - 1)

            if left_index >= 0:
                for number in range(0, 10):
                    if frequencies[number]==k:
                        if number > previous_digit:
                            result=''.join(str(digit) for digit in [number for _ in range(0, 3)])
                            
                            previous_digit=number

                left: int=int(num[left_index])

                frequencies[left]-=1

            i+=1

        return result

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        result: str=""

        triplets: List[str]=list()

        for digit in range(9, -1, -1):
            triplet: str=''.join(str(digit) for iteration in range(0, 3))

            triplets.append(triplet)

        for triplet in triplets:
            if num.find(triplet)!=-1:
                result=triplet

                break

        return result
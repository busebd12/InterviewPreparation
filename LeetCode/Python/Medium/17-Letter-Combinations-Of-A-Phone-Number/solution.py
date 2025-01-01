from collections import deque

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result: List[str]=list()

        n: int=len(digits)

        hashmap: Dict[int, List[chr]]=self.generate_hashmap()

        combination: List[chr]=list()

        index: int=0

        self.helper(digits, result, hashmap, combination, n, index)

        return result

    def generate_hashmap(self) -> Dict[int, List[chr]]:
        hashmap: Dict[int, List[chr]]=dict()
        
        hashmap[2]=list('abc')

        hashmap[3]=list('def')

        hashmap[4]=list('ghi')

        hashmap[5]=list('jkl')

        hashmap[6]=list('mno')

        hashmap[7]=list('pqrs')

        hashmap[8]=list('tuv')

        hashmap[9]=list('wxyz')

        return hashmap

    def helper(self, digits: str, result: List[str], hashmap: Dict[int, List[chr]], combination: List[chr], n: int, index: int) -> None:
        if index==n:
            if combination:
                result.append(''.join(combination.copy()))

            return

        for letter in hashmap[int(digits[index])]:
            combination.append(letter)

            self.helper(digits, result, hashmap, combination, n, index + 1)

            combination.pop()


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result: List[str]=list()

        n: int=len(digits)

        hashmap: Dict[int, List[chr]]=self.generate_hashmap()

        queue: Deque[List[chr]]=deque()

        queue.append(list())

        for digit in digits:
            qSize: int=len(queue)

            for count in range(0, qSize):
                combination: List[chr]=queue.popleft()

                for letter in hashmap[int(digit)]:
                    combination.append(letter)

                    queue.append(combination.copy())

                    combination.pop()

        while queue:
            combination: List[chr]=queue.popleft()

            if combination:
                result.append(''.join(combination))

        return result

    def generate_hashmap(self) -> Dict[int, List[chr]]:
        hashmap: Dict[int, List[chr]]=dict()
        
        hashmap[2]=list('abc')

        hashmap[3]=list('def')

        hashmap[4]=list('ghi')

        hashmap[5]=list('jkl')

        hashmap[6]=list('mno')

        hashmap[7]=list('pqrs')

        hashmap[8]=list('tuv')

        hashmap[9]=list('wxyz')

        return hashmap
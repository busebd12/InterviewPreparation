from collections import Counter, Deque

class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        result: str=""

        if k==0:
            return s

        hashmap: Dict[chr, int]=dict()

        for letter in s:
            if letter not in hashmap.keys():
                hashmap[letter]=1
            else:
                hashmap[letter]+=1

        max_heap: List[Tuple[int, chr]]=list()

        for (letter, frequency) in hashmap.items():
            heapq.heappush(max_heap, (-frequency, letter))

        used: Deque[Tuple[int, chr]]=deque()

        while max_heap:
            #If the max_heap has less than k letters in it and the letter with maximum frequency has a frequency of greater than one,
            #then we can't rearrange the remaining letters k distance apart since we don't enough other letters to place between the
            #letter with maximum frequency
            if len(max_heap) < k and (-1 * max_heap[0][0]) > 1:
                return ""

            limit: int=min(k, len(max_heap))

            for count in range(0, limit):
                frequency: int=(-1 * max_heap[0][0])

                letter: chr=max_heap[0][1]

                heapq.heappop(max_heap)

                result+=letter

                frequency-=1

                if frequency > 0:
                    used.append((-frequency, letter))
                    
            #Add the (frequency, letter) tuples back into the max_heap in the same order we removed them in
            while used:
                heapq.heappush(max_heap, used.popleft())

        return result

class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        result: str=""

        if k==0:
            return s

        hashmap: Counter[chr, int]=Counter(s)

        max_heap: List[Tuple[int, chr]]=list()

        for (letter, frequency) in hashmap.items():
            heapq.heappush(max_heap, (-frequency, letter))

        used: Deque[Tuple[int, chr]]=deque()

        while max_heap:
            if len(max_heap) < k and (-1 * max_heap[0][0]) > 1:
                return ""

            limit: int=min(k, len(max_heap))

            for count in range(0, limit):
                frequency: int=(-1 * max_heap[0][0])

                letter: chr=max_heap[0][1]

                heapq.heappop(max_heap)

                result+=letter

                frequency-=1

                if frequency > 0:
                    used.append((-frequency, letter))

            while used:
                heapq.heappush(max_heap, used.popleft())

        return result
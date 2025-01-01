from collections import Counter, deque, heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        result=0

        frequencies=Counter(tasks)

        max_heap=list()

        for (character, frequency) in frequencies.items():
            heapq.heappush(max_heap, (-frequency, character))

        while max_heap:
            gap_between_two_of_the_same_task=n + 1

            queue=deque()

            while max_heap and gap_between_two_of_the_same_task > 0:
                frequency=max_heap[0][0] * -1

                character=max_heap[0][1]

                heapq.heappop(max_heap)

                result+=1

                frequency-=1

                if frequency > 0:
                    queue.append((frequency, character))

                gap_between_two_of_the_same_task-=1

            if queue:
                for (frequency, character) in queue:
                    heapq.heappush(max_heap, (-frequency, character))

            if not max_heap:
                break
            else:
                result+=gap_between_two_of_the_same_task

        return result
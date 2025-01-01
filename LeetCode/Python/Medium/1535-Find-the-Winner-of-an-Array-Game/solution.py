from collections import deque

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        n: int=len(arr)

        if k >= n:
            return max(arr)

        queue: Deque[int]=deque(arr)

        rounds_won: int=0

        previous_winner: int=-1

        while rounds_won < k:
            first: int=queue.popleft()

            second: int=queue.popleft()

            larger: int=max(first, second)

            if larger==first:
                queue.append(second)

                queue.appendleft(first)
            else:
                queue.append(first)

                queue.appendleft(second)

            if previous_winner==-1:
                previous_winner=larger

                rounds_won=1
            else:
                if larger!=previous_winner:
                    previous_winner=larger

                    rounds_won=1
                else:
                    rounds_won+=1

        return previous_winner
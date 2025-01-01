from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        result=list()

        deck.sort(reverse=True)

        queue=deque(deck)

        ordering=deque()

        while queue:
            current=queue.popleft()
            
            if not ordering:
                ordering.appendleft(current)
            else:
                last=ordering.pop()

                ordering.appendleft(last)

                ordering.appendleft(current)

        result=[number for number in ordering]

        return result
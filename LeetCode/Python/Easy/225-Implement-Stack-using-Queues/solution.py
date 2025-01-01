from collections import deque

class MyStack:
    def __init__(self):
        self.queue: Deque[int]=deque()
        
    def push(self, x: int) -> None:
        self.queue.append(x)

        n: int=len(self.queue)

        for iteration in range(0, n - 1):
            self.queue.append(self.queue.popleft())

    def pop(self) -> int:
        return self.queue.popleft()

    def top(self) -> int:
        return self.queue[0]

    def empty(self) -> bool:
        return False if self.queue else True

class MyStack:
    def __init__(self):
        self.queue: Deque[int]=deque()
        
    def push(self, x: int) -> None:
        self.queue.appendleft(x)

    def pop(self) -> int:
        return self.queue.popleft()

    def top(self) -> int:
        return self.queue[0]

    def empty(self) -> bool:
        return False if self.queue else True
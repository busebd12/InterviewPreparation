import heapq

class SeatManager:
    def __init__(self, n: int):
        self.min_heap: List[int]=list()

        for seat in range(1, n + 1):
            heapq.heappush(self.min_heap, seat)

    def reserve(self) -> int:
        return heapq.heappop(self.min_heap)

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.min_heap, seatNumber)
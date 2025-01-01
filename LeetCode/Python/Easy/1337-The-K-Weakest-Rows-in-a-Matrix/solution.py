from collections import deque
import heapq

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        result: List[int]=list()

        rows: int=len(mat)

        hashmap: Dict[int, Deque[int]]=dict()

        for row in range(0, rows):
            soldiers: int=sum(mat[row])

            if soldiers not in hashmap.keys():
                hashmap[soldiers]=deque()
            
            hashmap[soldiers].append(row)

        min_heap: List[Tuple[int, Deque[int]]]=list()

        for (soldiers, rows_in_matrix) in hashmap.items():
            heapq.heappush(min_heap, (soldiers, rows_in_matrix))

        while min_heap and k > 0:
            soldiers, rows_in_matrix=heapq.heappop(min_heap)

            while rows_in_matrix and k > 0:
                result.append(rows_in_matrix.popleft())

                k-=1

            if k > 0 and rows_in_matrix:
                heapq.heappush(min_heap, (soliders, rows_in_matrix))

        return result
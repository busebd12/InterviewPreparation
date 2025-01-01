from collections import deque

class Solution:
    def integerBreak(self, n: int) -> int:
        result: int=0

        seen: Set[Tuple[int, int]]=set()

        queue: Deque[Tuple[int, int]]=deque()

        for number in range(1, n):
            total: int=number

            product: int=number

            seen.add((total, product))

            queue.append((total, product))

        while queue:
            current_total, current_product=queue.popleft()

            result=max(result, current_product)

            limit: int=n - current_total

            for number in range(1, limit + 1):
                next_total: int=current_total + number

                next_product: int=current_product * number

                if (next_total, next_product) not in seen:
                    seen.add((next_total, next_product))

                    queue.append((next_total, next_product))

        return result
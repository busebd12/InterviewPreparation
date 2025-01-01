from collections import deque

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph=dict()

        for flight in flights:
            source=flight[0]
            
            destination=flight[1]

            cost=flight[2]

            if source not in graph.keys():
                graph[source]=list()
            
            graph[source].append([destination, cost])

        costs=[float('inf') for _ in range(0, n)]

        costs[src]=0

        k+=1

        queue=deque()

        queue.append((src, 0))

        while k > 0 and queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                city, cost=queue.popleft()

                if city not in graph.keys():
                    continue

                for neighbour in graph[city]:
                    next_city=neighbour[0]

                    next_city_cost=neighbour[1]
                    
                    next_cost=cost + next_city_cost

                    if next_cost < costs[next_city]:
                        costs[next_city]=next_cost

                        queue.append((next_city, next_cost))

            k-=1

        return costs[dst] if costs[dst]!=float('inf') else -1
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        result: int=0

        graph: List[Set[int]]=[set() for iteration in range(0, n)]

        outdegree: List[int]=[0] * n

        for road in roads:
            city_a: int=road[0]

            city_b: int=road[1]

            graph[city_a].add(city_b)

            graph[city_b].add(city_a)

            outdegree[city_a]+=1

            outdegree[city_b]+=1

        for city_a in range(0, n):
            for city_b in range(0, n):
                if city_a!=city_b:
                    network_rank=outdegree[city_a] + outdegree[city_b]

                    if city_a in graph[city_b] or city_b in graph[city_a]:
                        network_rank-=1

                    result=max(result, network_rank)

        return result
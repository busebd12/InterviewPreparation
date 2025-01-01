class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        result=0

        n=len(costs)

        for row in range(1, n):
            costs[row][0]+=min(costs[row - 1][1], costs[row - 1][2])

            costs[row][1]+=min(costs[row - 1][0], costs[row - 1][2])

            costs[row][2]+=min(costs[row - 1][0], costs[row - 1][1])

        result=min(costs[n - 1])

        return result
'''
Solution 1: pure recursion.
'''
class Solution:
    def __init__(self):
        self.MOD=(10**9) + 7

    def knightDialer(self, n: int) -> int:
        result: int=0
        
        graph=self.build_graph()

        for start in range(0, 10):
            phone_numbers: int=self.dfs(graph, n - 1, start) % self.MOD

            result+=phone_numbers

        return result
    
    def dfs(self, graph: Dict[int, List[int]], n, node: int) -> int:
        if n==0:
            return 1
        
        if not graph[node]:
            return 0

        subproblem_solution: int=0

        for neighbour in graph[node]:
            if neighbour==node:
                continue

            subproblem_solution+=(self.dfs(graph, n - 1, neighbour) % self.MOD)

        subproblem_solution=(subproblem_solution % self.MOD)

        return subproblem_solution

    def build_graph(self) -> Dict[int, List[int]]:
        graph: Dict[int, List[int]]=dict()

        graph[0]=[4, 6]

        graph[1]=[6, 8]

        graph[2]=[7, 9]
        
        graph[3]=[4, 8]

        graph[4]=[0, 3, 9]

        graph[5]=list()

        graph[6]=[0, 1, 7]

        graph[7]=[2, 6]

        graph[8]=[1, 3]

        graph[9]=[2, 4]

        return graph
'''
Solution 2: recursion + memoization
'''
class Solution:
    def __init__(self):
        self.MOD=(10**9) + 7

        self.memo=None

    def knightDialer(self, n: int) -> int:
        result: int=0

        self.memo=[[-1 for _ in range(0, 10)] for _ in range(0, n + 1)]
        
        graph=self.build_graph()

        for start in range(0, 10):
            phone_numbers: int=self.dfs(graph, n - 1, start)

            result+=phone_numbers

        return result % self.MOD
    
    def dfs(self, graph: Dict[int, List[int]], n: int, node: int) -> int:
        if n==0:
            return 1

        if self.memo[n][node]!=-1:
            return self.memo[n][node]

        subproblem_solution: int=0

        for neighbour in graph[node]:
            subproblem_solution+=self.dfs(graph, n - 1, neighbour)

        self.memo[n][node]=subproblem_solution

        return subproblem_solution

    def build_graph(self) -> Dict[int, List[int]]:
        graph: Dict[int, List[int]]=dict()

        graph[0]=[4, 6]

        graph[1]=[6, 8]

        graph[2]=[7, 9]
        
        graph[3]=[4, 8]

        graph[4]=[0, 3, 9]

        graph[5]=list()

        graph[6]=[0, 1, 7]

        graph[7]=[2, 6]

        graph[8]=[1, 3]

        graph[9]=[2, 4]

        return graph
'''
Solution 1: graph + recursive depth-first search
'''
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        result: List[int]=list()

        n: int=self.count_unique_numbers(adjacentPairs)

        graph: Dict[int, List[int]]=self.build_graph(adjacentPairs)

        starting_node: int=self.get_starting_node(adjacentPairs)

        visited: Set[int]=set()

        self.dfs(graph, result, visited, n, starting_node)

        return result

    def count_unique_numbers(self, adjacentPairs: List[List[int]]) -> int:
        seen: Set[int]=set()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in seen:
                seen.add(u)

            if v not in seen:
                seen.add(v)

        return len(seen)

    def get_starting_node(self, adjacentPairs: List[List[int]]) -> int:
        frequencies: Dict[int, int]=dict()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in frequencies.keys():
                frequencies[u]=1
            else:
                frequencies[u]+=1

            if v not in frequencies.keys():
                frequencies[v]=1
            else:
                frequencies[v]+=1

        starting_node: int=-1

        for (number, frequency) in frequencies.items():
            if frequency==1:
                starting_node=number

                break

        return starting_node

    def build_graph(self, adjacentPairs: List[List[int]]) -> Dict[int, List[int]]:
        graph: Dict[int, List[int]]=dict()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in graph.keys():
                graph[u]=list()
            
            graph[u].append(v)

            if v not in graph.keys():
                graph[v]=list()
            
            graph[v].append(u)

        return graph

    def dfs(self, graph: Dict[int, List[int]], result: List[int], visited: Set[int], n: int, node: int) -> None:
        if len(result)==n:
            return

        if node in visited:
            return

        visited.add(node)

        result.append(node)

        for neighbour in graph[node]:
            self.dfs(graph, result, visited, n, neighbour)

'''
Solution 2: graph + iterative depth-first search
'''
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        result: List[int]=list()

        n: int=self.get_n(adjacentPairs)

        graph: Dict[int, List[int]]=self.build_graph(adjacentPairs)

        starting_node: int=self.get_starting_node(adjacentPairs)

        visited: Set[int]=set()

        self.dfs(graph, result, visited, n, starting_node)

        return result

    def get_n(self, adjacentPairs: List[List[int]]) -> int:
        seen: Set[int]=set()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in seen:
                seen.add(u)

            if v not in seen:
                seen.add(v)

        return len(seen)

    def get_starting_node(self, adjacentPairs: List[List[int]]) -> int:
        frequencies: Dict[int, int]=dict()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in frequencies.keys():
                frequencies[u]=1
            else:
                frequencies[u]+=1

            if v not in frequencies.keys():
                frequencies[v]=1
            else:
                frequencies[v]+=1

        starting_node: int=-1

        for (number, frequency) in frequencies.items():
            if frequency==1:
                starting_node=number

                break

        return starting_node

    def build_graph(self, adjacentPairs: List[List[int]]) -> Dict[int, List[int]]:
        graph: Dict[int, List[int]]=dict()

        for pair in adjacentPairs:
            u: int=pair[0]

            v: int=pair[1]

            if u not in graph.keys():
                graph[u]=list()
            
            graph[u].append(v)

            if v not in graph.keys():
                graph[v]=list()
            
            graph[v].append(u)

        return graph

    def dfs(self, graph: Dict[int, List[int]], result: List[int], visited: Set[int], n: int, node: int) -> None:
        stack: List[int]=list()

        stack.append(node)

        while stack and len(visited) < n:
            current: int=stack.pop()

            if current in visited:
                continue

            result.append(current)

            visited.add(current)

            for neighbour in graph[current]:
                stack.append(neighbour)
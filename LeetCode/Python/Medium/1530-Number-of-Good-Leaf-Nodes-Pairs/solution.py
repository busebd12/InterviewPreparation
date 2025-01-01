from collections import deque

class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        result=0

        graph=self.build_graph(root)

        leaf_nodes=self.get_leaf_nodes(root)

        for leaf_node in leaf_nodes:
            result+=self.explore_from_leaf_node(graph, leaf_nodes, distance, leaf_node)

        result//=2

        return result
        
    def build_graph(self, root: TreeNode) -> Dict[TreeNode, List[TreeNode]]:
        graph=dict()

        queue=deque()

        queue.append(root)

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                parent=queue.popleft()

                if parent not in graph.keys():
                    graph[parent]=list()

                if parent.left is not None:
                    graph[parent].append(parent.left)

                    if parent.left not in graph.keys():
                        graph[parent.left]=list()

                    graph[parent.left].append(parent)

                    queue.append(parent.left)

                if parent.right is not None:
                    graph[parent].append(parent.right)

                    if parent.right not in graph.keys():
                        graph[parent.right]=list()

                    graph[parent.right].append(parent)

                    queue.append(parent.right)

        return graph

    def get_leaf_nodes(self, root: TreeNode) -> Set[TreeNode]:
        leaf_nodes=set()

        queue=deque()

        queue.append(root)

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                parent=queue.popleft()

                if parent.left is None and parent.right is None:
                    leaf_nodes.add(parent)

                    continue

                if parent.left is not None:
                    queue.append(parent.left)

                if parent.right is not None:
                    queue.append(parent.right)

        return leaf_nodes

    def explore_from_leaf_node(self, graph: Dict[TreeNode, List[TreeNode]], leaf_nodes: Set[TreeNode], distance: int, leaf: TreeNode) -> int:
        pairs=0

        queue=deque()

        queue.append(leaf)

        visited=set()

        while queue and distance >= 0:
            q_size=len(queue)

            for iteration in range(0, q_size):
                node=queue.popleft()

                if node in visited:
                    continue

                visited.add(node)

                if node in leaf_nodes and node!=leaf:
                    pairs+=1

                for neighbour in graph[node]:
                    queue.append(neighbour)

            distance-=1

        return pairs
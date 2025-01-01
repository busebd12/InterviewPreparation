from collections import deque

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        child_nodes: Set[int]=set()

        for node in range(0, n):
            left_child: int=leftChild[node]

            right_child: int=rightChild[node]

            if left_child!=-1:
                child_nodes.add(left_child)

            if right_child!=-1:
                child_nodes.add(right_child)

        root_nodes: int=0

        for node in range(0, n):
            if node not in child_nodes:
                root_nodes+=1

        if root_nodes==0 or root_nodes > 1:
            return False

        root: int=-1

        for node in range(0, n):
            if node not in child_nodes:
                root=node

                break

        visited: Set[int]=set()

        queue: Deque[int]=deque()

        queue.append(root)

        while queue:
            q_size: int=len(queue)

            for iteration in range(0, q_size):
                node: int=queue.popleft()

                if node in visited:
                    return False

                visited.add(node)

                left_child: int=leftChild[node]

                right_child: int=rightChild[node]

                if left_child!=-1:
                    queue.append(left_child)

                if right_child!=-1:
                    queue.append(right_child)

        return len(visited)==n
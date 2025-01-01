from collections import deque

class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        queue=deque()

        queue.append((root, 0))

        while queue:
            q_size=len(queue)

            previous=-1

            for iteration in range(0, q_size):
                node, level=queue.popleft()

                is_valid, __previous=self.is_valid_node(node, level, previous)

                if not is_valid:
                    return False

                previous=__previous

                if node.left:
                    queue.append((node.left, level + 1))
                
                if node.right:
                    queue.append((node.right, level + 1))

        return True

    def is_valid_node(self, node: Optional[TreeNode], level: int, previous: int) -> (bool, int):
        if level % 2 == 0:
            if node.val % 2 == 0:
                return (False, -1)
            
            if previous==-1:
                previous=node.val
            else:
                if node.val <= previous:
                    return (False, -1)
                
                previous=node.val
        else:
            if node.val % 2 == 1:
                return (False, -1)

            if previous==-1:
                previous=node.val
            else:
                if node.val >= previous:
                    return (False, -1)

                previous=node.val

        return (True, previous)
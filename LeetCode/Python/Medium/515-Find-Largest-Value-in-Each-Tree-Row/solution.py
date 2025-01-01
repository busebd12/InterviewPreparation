from collections import deque

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int]=list()

        min_int: int=-(2**31) - 1

        queue: Deque[Optional[TreeNode]]=deque()

        queue.append(root)

        while queue:
            nodes_in_current_level: int=len(queue)

            max_in_current_level: int=min_int

            for iteration in range(0, nodes_in_current_level):
                node: Optional[TreeNode]=queue.popleft()

                if node:
                    max_in_current_level=max(max_in_current_level, node.val)

                    if node.left:
                        queue.append(node.left)

                    if node.right:
                        queue.append(node.right)

            if max_in_current_level!=min_int:
                result.append(max_in_current_level)

        return result
from collections import deque

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        result=0

        last_level=self.get_height(root)

        result=self.get_leftmost_node_in_bottom_row(root, last_level)

        return result

    def get_height(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_subtree_height=self.get_height(root.left)

        right_subtree_height=self.get_height(root.right)

        return 1 + max(left_subtree_height, right_subtree_height)

    def get_leftmost_node_in_bottom_row(self, root: Optional[TreeNode], last_level: int) -> int:
        queue=deque()

        queue.append(root)

        level=1

        left_most_node=-1

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                node=queue.popleft()

                if level==last_level and iteration==0:
                    left_most_node=node.val

                    break

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            if queue:
                level+=1

        return left_most_node
from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        result=list()

        queue=deque()

        queue.append(root)

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                parent=queue.popleft()

                children=0

                if parent.left and parent.right==None:
                    result.append(parent.left.val)

                    queue.append(parent.left)
                elif parent.left==None and parent.right:
                    result.append(parent.right.val)

                    queue.append(parent.right)
                elif parent.left and parent.right:
                    queue.append(parent.left)

                    queue.append(parent.right)

        return result
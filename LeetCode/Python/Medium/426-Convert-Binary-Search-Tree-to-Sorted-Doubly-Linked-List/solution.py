"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None
        
        head=None

        previous=None

        stack=list()

        current=root

        while stack or current:
            while current:
                stack.append(current)

                current=current.left

            current=stack.pop()

            if previous is not None:
                previous.right=current

                current.left=previous
            else:
                head=current

            previous=current

            current=current.right

        head.left=previous

        previous.right=head

        return head
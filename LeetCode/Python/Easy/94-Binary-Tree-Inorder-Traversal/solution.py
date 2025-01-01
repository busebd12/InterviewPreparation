class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int]=list()

        self.helper(result, root)

        return result

    def helper(self, result: List[int], root: Optional[TreeNode]) -> None:
        if not root:
            return

        self.helper(result, root.left)

        result.append(root.val)

        self.helper(result, root.right)

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int]=list()

        stack: List[Optional[TreeNode]]=list()

        current: Optional[TreeNode]=root

        while stack or current:
            while current:
                stack.append(current)

                current=current.left

            node: Optional[TreeNode]=stack.pop()

            result.append(node.val)

            current=node.right

        return result
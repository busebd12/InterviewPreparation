class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        (tree_flag, result)=self.in_order_traversal(root, False)

        return result

    def in_order_traversal(self, root: Optional[TreeNode], came_from_left: bool) -> (bool, int):
        if not root:
            return (False, 0)
        
        if not root.left and not root.right:
            if came_from_left:
                return (True, root.val)
            else:
                return (False, 0)

        subtree_total=0

        subtree_flag=False

        left_subtree_flag, left_subtree_total=self.in_order_traversal(root.left, True)

        right_subtree_flag, right_subtree_total=self.in_order_traversal(root.right, False)

        if left_subtree_flag:
            subtree_total+=left_subtree_total

            subtree_flag=True

        if right_subtree_flag:
            subtree_total+=right_subtree_total

            subtree_flag=True

        return (subtree_flag, subtree_total)

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        result=0

        stack=list()

        stack.append((False, root))

        while stack:
            came_from_left, parent=stack.pop()

            if parent.left==None and parent.right==None:
                if came_from_left:
                    result+=parent.val

                continue

            if parent.right:
                stack.append((False, parent.right))

            if parent.left:
                stack.append((True, parent.left))

        return result
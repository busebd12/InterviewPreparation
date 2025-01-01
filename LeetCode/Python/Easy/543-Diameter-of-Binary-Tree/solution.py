class Solution:
    def __init__(self):
        self.result=0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.helper(root)

        return self.result

    def helper(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_subtree_path_length: int=self.helper(root.left)

        right_subtree_path_length: int=self.helper(root.right)

        path_length: int=left_subtree_path_length + right_subtree_path_length

        self.result=max(self.result, path_length)

        return 1 + max(left_subtree_path_length, right_subtree_path_length) 
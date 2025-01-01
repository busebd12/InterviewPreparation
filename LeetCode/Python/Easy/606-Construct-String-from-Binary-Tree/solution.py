class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
      if not root:
        return ""

      root_string: str=str(root.val)

      left_subtree: str=self.tree2str(root.left)

      right_subtree: str=self.tree2str(root.right)

      if left_subtree and right_subtree:
        root_string=root_string + "(" + left_subtree + ")" + "(" + right_subtree + ")"
      elif not left_subtree and right_subtree:
        root_string=root_string + "()" + "(" + right_subtree + ")"
      elif left_subtree and not right_subtree:
        root_string=root_string + "(" + left_subtree + ")"

      return root_string
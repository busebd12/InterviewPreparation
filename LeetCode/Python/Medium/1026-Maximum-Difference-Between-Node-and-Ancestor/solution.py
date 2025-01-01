class Solution:
    def __init__(self):
        self.result=0

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.helper(root)

        return self.result
    
    def helper(self, root: Optional[TreeNode]) -> (float, float):
        if not root:
            return (float('inf'), float('-inf'))

        left_subtree_min_value, left_subtree_max_value=self.helper(root.left)

        right_subtree_min_value, right_subtree_max_value=self.helper(root.right)

        current_subtree_min_value=min(root.val, left_subtree_min_value, right_subtree_min_value)

        current_subtree_max_value=max(root.val, left_subtree_max_value, right_subtree_max_value)

        self.result=max(self.result, abs(current_subtree_min_value - root.val), abs(current_subtree_max_value - root.val))

        return (current_subtree_min_value, current_subtree_max_value)
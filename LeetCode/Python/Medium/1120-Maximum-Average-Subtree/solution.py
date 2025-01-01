class Solution:
    def __init__(self):
        self.result=0

    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        nodes_in_tree, tree_average=self.helper(root)

        return self.result

    def helper(self, root: Optional[TreeNode]) -> (int, float):
        if not root:
          return (0, 0)

        nodes_in_current_subtree=1

        left_subtree_nodes, left_subtree_total=self.helper(root.left)

        right_subtree_nodes, right_subtree_total=self.helper(root.right)

        nodes_in_current_subtree+=left_subtree_nodes

        nodes_in_current_subtree+=right_subtree_nodes

        subtree_total=float(root.val + left_subtree_total + right_subtree_total)

        subtree_average=subtree_total / nodes_in_current_subtree

        self.result=max(self.result, subtree_average)

        return (nodes_in_current_subtree, subtree_total)
class Solution:
    def __init__(self):
        self.result=0

    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        nodes_in_tree, tree_total=self.helper(root)

        return self.result

    def helper(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if not root:
            return (0, 0)

        subtree_total: int=root.val

        left_subtree_nodes, left_subtree_total=self.helper(root.left)

        right_subtree_nodes, right_subtree_total=self.helper(root.right)

        subtree_total+=left_subtree_total

        subtree_total+=right_subtree_total

        nodes_in_subtree: int=1 + left_subtree_nodes + right_subtree_nodes

        subtree_average: int=subtree_total // nodes_in_subtree

        if root.val==subtree_average:
            self.result+=1

        return (nodes_in_subtree, subtree_total)
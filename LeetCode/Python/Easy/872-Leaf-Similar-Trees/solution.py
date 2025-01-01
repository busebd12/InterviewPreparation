class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        tree1_leaf_nodes: List[int]=list()

        self.get_leaf_nodes(root1, tree1_leaf_nodes)

        tree2_leaf_nodes: List[int]=list()

        self.get_leaf_nodes(root2, tree2_leaf_nodes)

        return tree1_leaf_nodes==tree2_leaf_nodes

    def get_leaf_nodes(self, root: Optional[TreeNode], leaf_nodes: List[int]) -> bool:
        if not root:
            return

        if not root.left and not root.right:
            leaf_nodes.append(root.val)

        self.get_leaf_nodes(root.left, leaf_nodes)

        self.get_leaf_nodes(root.right, leaf_nodes)

class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        tree1_leaf_nodes: List[int]=list()

        self.get_leaf_nodes(root1, tree1_leaf_nodes)

        tree2_leaf_nodes: List[int]=list()

        self.get_leaf_nodes(root2, tree2_leaf_nodes)

        return tree1_leaf_nodes==tree2_leaf_nodes

    def get_leaf_nodes(self, root: Optional[TreeNode], leaf_nodes: List[int]) -> None:
        if not root:
            return

        stack=list()

        stack.append(root)

        while stack:
            node=stack.pop()

            is_leaf=True

            if node.right:
                is_leaf=False

                stack.append(node.right)

            if node.left:
                is_leaf=False

                stack.append(node.left)

            if is_leaf:
                leaf_nodes.append(node.val)
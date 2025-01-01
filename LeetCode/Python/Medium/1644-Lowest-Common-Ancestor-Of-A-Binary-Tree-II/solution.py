class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not self.is_in_tree(root, p) or not self.is_in_tree(root, q):
            return None
        
        result: 'TreeNode'=self.helper(root, p, q)

        return result

    def is_in_tree(self, root: 'TreeNode', node: 'TreeNode') -> bool:
        if root is None:
            return False
        
        if root.left is None and root.right is None:
            return root==node

        if root.val==node.val:
            return True

        is_in_left_subtree: bool=self.is_in_tree(root.left, node)

        is_in_right_subtree: bool=self.is_in_tree(root.right, node)

        return is_in_left_subtree or is_in_right_subtree

    def helper(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root==None:
            return root

        if root==p or root==q:
            return root

        left_subtree: 'TreeNode'=self.helper(root.left, p, q)

        right_subtree: 'TreeNode'=self.helper(root.right, p, q)

        if left_subtree is not None and right_subtree is not None:
            return root

        return right_subtree if left_subtree is None else left_subtree
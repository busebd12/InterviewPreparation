# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        return self.dfs(root, p, q)

    def dfs(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root.val==p.val or root.val==q.val:
            return root

        left=self.dfs(root.left, p, q)

        right=self.dfs(root.right, p, q)

        if left is not None and right is not None:
            return root

        return right if left is None else left
class Solution:
    def __init__(self):
        self.result=0
    
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        self.helper(root)

        return self.result

    def helper(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        descendants_sum=0

        left_subtree_sum=self.helper(root.left)

        right_subtree_sum=self.helper(root.right)

        descendants_sum+=left_subtree_sum

        descendants_sum+=right_subtree_sum

        if descendants_sum==root.val:
            self.result+=1

        subtree_sum=descendants_sum + root.val

        return subtree_sum 
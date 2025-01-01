class Solution:
    def __init__(self):
        self.result=0

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.helper(root, low, high)

        return self.result

    def helper(self, root: Optional[TreeNode], low: int, high: int):
        if not root:
            return

        if low <= root.val and root.val <= high:
            self.result+=root.val

        self.helper(root.left, low, high)

        self.helper(root.right, low, high)

class Solution:
    def __init__(self):
        self.result=0

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.helper(root, low, high)

        return self.result

    def helper(self, root: Optional[TreeNode], low: int, high: int):
        if not root:
            return

        if low <= root.val and root.val <= high:
            self.result+=root.val

            self.helper(root.left, low, high)

            self.helper(root.right, low, high)
        elif root.val < low:
            self.helper(root.right, low, high)
        elif root.val > high:
            self.helper(root.left, low, high)
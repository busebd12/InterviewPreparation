class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root.left, root.right)

    def helper(self, left_subtree: Optional[TreeNode], right_subtree: Optional[TreeNode]) -> bool:
        if not left_subtree and not right_subtree:
            return True
        
        if not left_subtree or not right_subtree:
            return False

        return left_subtree.val==right_subtree.val and self.helper(left_subtree.right, right_subtree.left) and self.helper(left_subtree.left, right_subtree.right)

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        left_subtree_queue: Deque[Optional[TreeNode]]=deque()

        right_subtree_queue: Deque[Optional[TreenNode]]=deque()

        left_subtree_queue.append(root.left)

        right_subtree_queue.append(root.right)

        while left_subtree_queue and right_subtree_queue:
            if len(left_subtree_queue)!=len(right_subtree_queue):
                return False

            nodes_in_current_level: int=len(left_subtree_queue)

            for iteration in range(0, nodes_in_current_level):
                left_subtree_node: Optional[TreeNode]=left_subtree_queue.popleft()

                right_subtree_node: Optional[TreeNode]=right_subtree_queue.pop()

                if (not left_subtree_node and right_subtree_node) or (left_subtree_node and not right_subtree_node):
                    return False

                if not left_subtree_node and not right_subtree_node:
                    continue

                if left_subtree_node.val!=right_subtree_node.val:
                    return False

                if left_subtree_node:
                    left_subtree_queue.append(left_subtree_node.left)

                    left_subtree_queue.append(left_subtree_node.right)
                
                if right_subtree_node:
                    right_subtree_queue.appendleft(right_subtree_node.right)

                    right_subtree_queue.appendleft(right_subtree_node.left)

        return True
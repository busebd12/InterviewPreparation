class Solution:
    __int_max: int=None

    def minDepth(self, root: Optional[TreeNode]) -> int:
        self.__int_max=pow(2, 53) - 1

        if root==None:
            return 0
        
        return self.helper(root)

    def helper(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return self.__int_max
        
        nodes: int=1

        left_subtree_result: int=self.helper(root.left)

        right_subtree_result: int=self.helper(root.right)

        if left_subtree_result==self.__int_max and right_subtree_result==self.__int_max:
            return nodes
        elif left_subtree_result!=self.__int_max and right_subtree_result==self.__int_max:
            return nodes + left_subtree_result
        elif right_subtree_result!=self.__int_max and left_subtree_result==self.__int_max:
            return nodes + right_subtree_result
        else:
            return nodes + min(left_subtree_result, right_subtree_result)

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        result: int=0

        queue: deque[TreeNode]=deque()

        queue.append(root)

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                node: TreeNode=queue.popleft()

                if node is None:
                    continue

                if node.left is None and node.right is None:
                    return result + 1
                
                if node.left is not None:
                    queue.append(node.left)

                if node.right is not None:
                    queue.append(node.right)
            
            if queue:
                result+=1

        return result
from collections import deque

class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        visited: Set[TreeNode]=set()

        queue: Deque[Tuple[TreeNode, TreeNode]]=deque()

        queue.append((root, None))

        while queue:
            node_in_current_level: int=len(queue)

            for iteration in range(0, node_in_current_level):
                node, parent=queue.popleft()

                visited.add(node)

                #If the right child is not null
                if node.right:
                    #If we've already visited the right child, then the current node is invalid
                    if node.right in visited:
                        if parent.left==node:
                            parent.left=None
                        else:
                            parent.right=None
                    else:
                        #Add the right child to the queue first so we visit right child nodes before left child nodes
                        queue.append((node.right, node))

                if node.left:
                    queue.append((node.left, node))

        return root
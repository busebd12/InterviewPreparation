from collections import deque

class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result=list()

        if not root:
            return result

        hashmap, min_column, max_column=self.build_hashmap(root)

        for column in range(max_column, min_column-1, -1):
            result.append(hashmap[column])

        return result

    def build_hashmap(self, root: Optional[TreeNode]) -> (Dict[int, int], int, int):
        hashmap=dict()

        min_column=(2**53)-1

        max_column=0

        queue=deque()

        queue.append((root, 0))

        while queue:
            node, column=queue.popleft()

            if column not in hashmap.keys():
                hashmap[column]=list()

            hashmap[column].append(node.val)

            min_column=min(min_column, column)

            max_column=max(max_column, column)

            if node.left:
                queue.append((node.left, column + 1))
            
            if node.right:
                queue.append((node.right, column - 1))

        return (hashmap, min_column, max_column)
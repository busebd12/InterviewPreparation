from collections import deque

class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        result=0

        queue=deque()

        hashmap=[0 for _ in range(0, 10)]

        hashmap[root.val]+=1

        queue.append((root, hashmap))

        while queue:
            q_length=len(queue)

            for count in range(0, q_length):
                node, current_hashmap=queue.popleft()

                if not node.left and not node.right:
                    if self.is_palindrome(current_hashmap):
                        result+=1
                
                if node.left:
                    left_node_hashmap=current_hashmap.copy()

                    left_node_hashmap[node.left.val]+=1

                    queue.append((node.left, left_node_hashmap))

                if node.right:
                    right_node_hashmap=current_hashmap.copy()

                    right_node_hashmap[node.right.val]+=1

                    queue.append((node.right, right_node_hashmap))

        return result

    def is_palindrome(self, hashmap: List[int]) -> bool:
        even_count=0

        odd_count=0
        
        for digit in range(0, 10):
            frequency=hashmap[digit]
            
            if frequency > 0:
                if frequency % 2 == 0:
                    even_count+=1
                else:
                    odd_count+=1

        return True if even_count >= 0 and odd_count <= 1 else False
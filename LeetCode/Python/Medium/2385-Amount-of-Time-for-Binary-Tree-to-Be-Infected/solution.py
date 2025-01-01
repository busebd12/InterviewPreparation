from collections import deque

class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        result=0

        hashmap=self.build_hashmap(root)

        result=self.bfs(hashmap, start)

        return result

    def build_hashmap(self, root: Optional[TreeNode]) -> Dict[int, List[int]]:
        hashmap=dict()

        queue=deque()

        queue.append(root)

        while queue:
            q_size=len(queue)

            for count in range(0, q_size):
                parent=queue.popleft()

                if parent.val not in hashmap.keys():
                    hashmap[parent.val]=list()

                if parent.left:
                    hashmap[parent.val].append(parent.left.val)

                    if parent.left.val not in hashmap.keys():
                        hashmap[parent.left.val]=list()

                    hashmap[parent.left.val].append(parent.val)

                    queue.append(parent.left)

                if parent.right:
                    hashmap[parent.val].append(parent.right.val)

                    if parent.right.val not in hashmap.keys():
                        hashmap[parent.right.val]=list()

                    hashmap[parent.right.val].append(parent.val)

                    queue.append(parent.right)

        return hashmap

    def bfs(self, hashmap: Dict[int, List[int]], start: int) -> int:
        total_time=0
        
        queue=deque()

        limit=(10**5) + 1

        visited=[False for _ in range(0, limit)]

        visited[start]=True

        queue.append(start)

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                node=queue.popleft()

                for neighbour in hashmap[node]:
                    if not visited[neighbour]:
                        queue.append(neighbour)

                        visited[neighbour]=True

            if queue:
                total_time+=1


        return total_time
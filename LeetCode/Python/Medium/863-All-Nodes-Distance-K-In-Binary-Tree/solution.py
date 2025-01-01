from collections import deque

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        result: list[int]=None
        
        hashmap: dict[int, list[int]]=self.populate_hashmap(root)

        result=self.get_nodes(hashmap, target, k)

        return result

    def populate_hashmap(self, root: TreeNode) -> dict[int, list[int]]:
        hashmap: dict[int, list[int]]=dict()

        #Queue used for breadth-first traversal
        queue: deque[TreeNode]=deque()

        queue.append(root)

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                parent: TreeNode=queue.popleft()

                #Add parent node value to hashmap
                if parent.val not in hashmap:
                    hashmap[parent.val]=list()

                #If the left child node is not None(null)
                if parent.left is not None:
                    #Add the left child value to the hashmap
                    if parent.left.val not in hashmap:
                        hashmap[parent.left.val]=list()
                    
                    #Create reverse mapping between left child node value and parent node value
                    hashmap[parent.left.val].append(parent.val)

                    #Create mapping between parent node value and left child node value
                    hashmap[parent.val].append(parent.left.val)

                    #Add left child node value to the queue
                    queue.append(parent.left)

                #If the right child is not None(null)
                if parent.right is not None:
                    #If the right child node value is not in the hashmap
                    if parent.right.val not in hashmap:
                        hashmap[parent.right.val]=list()
                    
                    #Create reverse mapping between right node value and parent value
                    hashmap[parent.right.val].append(parent.val)

                    #Create mapping between parent node value and right child node value
                    hashmap[parent.val].append(parent.right.val)

                    #Add right child node value to the queue
                    queue.append(parent.right)

        return hashmap

    def get_nodes(self, hashmap: dict[int, list[int]], target: TreeNode, k: int) -> list[int]:
        nodes: list[int]=list()
        
        #Queue used for breadth-first traversal
        queue: deque[int]=deque()

        queue.append(target.val)

        #Visited set to make sure we don't visit a node more than once
        visited: set[int]=set()

        #Mark target as visited
        visited.add(target.val)

        distance: int=0

        #While the queue is not empty and we haven't travelled distance k in the tree
        while queue and distance < k:
            qSize: int=len(queue)

            for count in range(0, qSize):
                #Remove first node value from the queue
                node: int=queue.popleft()

                #Iterate through all neighbour's in the hashmap
                for neighbour in hashmap[node]:
                    #If we haven't visited the neighbour before
                    if neighbour not in visited:
                        #Add the neighbour to the hashmap
                        visited.add(neighbour)
                        
                        #Add the neighbour to the queue
                        queue.append(neighbour)
            #If there node values in the queue
            if queue:
                distance+=1

        #At this point, if the queue is not empty, then it will hold all nodes distance k away from target
        #While the queue is not empty
        while queue:
            #Remove the node value
            node: TreeNode=queue.popleft()

            #Add the node's value to the result list
            nodes.append(node)

        return nodes


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        result: list[int]=None
        
        hashmap: dict[int, deque[int]]=self.populate_hashmap(root)

        result=self.get_nodes(hashmap, target, k)

        return result

    def populate_hashmap(self, root: TreeNode) -> dict[int, deque[int]]:
        hashmap: dict[int, deque[int]]=dict()

        queue: deque[TreeNode]=deque()

        queue.append(root)

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                parent: TreeNode=queue.popleft()

                if parent.val not in hashmap:
                    hashmap[parent.val]=deque()

                if parent.left is not None:
                    if parent.left.val not in hashmap:
                        hashmap[parent.left.val]=deque()
                    
                    hashmap[parent.left.val].append(parent.val)

                    hashmap[parent.val].append(parent.left.val)

                    queue.append(parent.left)

                if parent.right is not None:
                    if parent.right.val not in hashmap:
                        hashmap[parent.right.val]=deque()
                    
                    hashmap[parent.right.val].append(parent.val)

                    hashmap[parent.val].append(parent.right.val)

                    queue.append(parent.right)

        return hashmap

    def get_nodes(self, hashmap: dict[int, deque[int]], target: TreeNode, k: int) -> list[int]:
        nodes: list[int]=list()
        
        queue: deque[int]=deque()

        queue.append(target.val)

        distance: int=0

        while queue and distance < k:
            qSize: int=len(queue)

            for count in range(0, qSize):
                node: int=queue.popleft()

                #While this node still has neighbour's in the hashmap
                while hashmap[node]:
                    #Remove neighbour from the hashmap
                    neighbour: int=hashmap[node].popleft()

                    #Only add the neighbour value to the queue if it still has neighbours
                    #If the neighbour value still has neighbours, then we haven't visited it yet
                    #If the neighbour value did not have neighbours, then we know we've already visited it since we remove all a node's neighbours when we do
                    if hashmap[neighbour]:
                        queue.append(neighbour)

            if queue:
                distance+=1

        while queue:
            node: int=queue.popleft()

            nodes.append(node)

        return nodes

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        result: list[int]=None
        
        hashmap: dict[int, list[int]]=self.populate_hashmap(root)

        result=self.get_nodes(hashmap, target, k)

        return result

    def populate_hashmap(self, root: TreeNode) -> dict[int, list[int]]:
        hashmap: dict[int, list[int]]=dict()

        queue: deque[TreeNode]=deque()

        queue.append(root)

        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                parent: TreeNode=queue.popleft()

                if parent.val not in hashmap:
                    hashmap[parent.val]=list()

                if parent.left is not None:
                    if parent.left.val not in hashmap:
                        hashmap[parent.left.val]=list()
                    
                    hashmap[parent.left.val].append(parent.val)

                    hashmap[parent.val].append(parent.left.val)

                    queue.append(parent.left)

                if parent.right is not None:
                    if parent.right.val not in hashmap:
                        hashmap[parent.right.val]=list()
                    
                    hashmap[parent.right.val].append(parent.val)

                    hashmap[parent.val].append(parent.right.val)

                    queue.append(parent.right)

        return hashmap

    def get_nodes(self, hashmap: dict[int, list[int]], target: TreeNode, k: int) -> list[int]:
        nodes: list[int]=list()
        
        queue: deque[int]=deque()

        queue.append(target.val)

        distance: int=0

        while queue and distance < k:
            qSize: int=len(queue)

            for count in range(0, qSize):
                node: int=queue.popleft()

                while hashmap[node]:
                    neighbour: int=hashmap[node].pop()
                    if hashmap[neighbour]:
                        queue.append(neighbour)

            if queue:
                distance+=1

        while queue:
            node: int=queue.popleft()

            nodes.append(node)

        return nodes
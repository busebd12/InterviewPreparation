from collections import deque

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        result: list[int]=list()

        n: int=len(graph)

        edges: list[list[int]]=[[] for iteration in range(0, n)]

        #Used to count the number of outgoing edges for each node in the graph
        outdegree: list[int]=[0] * n

        #For every node in the graph
        for u in range(0, n):
            #If the node has outgoing edges
            if graph[u]:
                #For each outgoing edge
                for v in graph[u]:
                    #Build the edge between the source and destination node
                    #IMPORTANT: we are building the edge in reverse order: destination -> source
                    edges[v].append(u)
                    #Increment the outdegree of the current node
                    outdegree[u]+=1

        #Queue used for topological sort
        queue: deque[int]=deque()

        #For every node in the graph
        for start in range(0, n):
            #If the outdegree of the node is zero, then this is a terminal node and we want to start the topological sort from this node
            if outdegree[start]==0:
                queue.append(start)

        #Keeps track of whether a node is safe
        is_safe: list[bool]=[False] * n

        #Do the topological sort now
        #IMPORTANT: We start the topological sort from the terminal nodes and move through the graph in the reverse direction.
        #This way, each additional node that we reach satisfies the condition for being a safe node since we reached the
        #node from either another safe node or directly from a terminal node
        while queue:
            qSize: int=len(queue)

            for count in range(0, qSize):
                #Remove the node from the queue
                node=queue.popleft()

                #Mark the node as safe
                is_safe[node]=True

                #For each node that has an edge that goes into the node we just removed from the queue
                for neighbour in edges[node]:
                    #Decrement the outdegree
                    outdegree[neighbour]-=1

                    #If the outdegree reaches zero
                    if outdegree[neighbour]==0:
                        #Add it to the queue
                        queue.append(neighbour)

        #For each node in the graph
        for node in range(0, n):
            #If it is safe
            if is_safe[node]:
                #Add it to the result
                result.append(node)

        return result
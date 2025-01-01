from collections import deque

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        result: int=0

        if not graph:
            return result

        all_empty: bool=True

        for element in graph:
            if element:
                all_empty=False

        if all_empty:
            return result

        n: int=len(graph)

        #The idea is to use a bitmask, or the binary representation of a number to mark whether or not we've visited a node in the graph
        #Since there are n nodes, we an integer value of 2^n to have enough bits for each node in the graph
        #However, since the nodes of the graph are labeled from 0 to n-1, we only need an integer value of 2^(n) - 1
        #Once the bit at the n-1 position from the left is set to 1 in the current bitmask, we know we've reached the last node in the graph
        all_visited: int=(1 << n) - 1

        queue: Deque[List[int]]=deque()

        visited: Set[Tuple[int, int]]=set()

        #Since we can start traversing the graph from any node, start by enqueueing all each node of the graph as a possible starting point
        for node in range(0, n):
            #Bitmask where the node-th bit position from the left is set to 1 indicating that we've visited this node in our path
            mask: int=(1 << node)

            queue.append([node, mask, 0])

            #Mark the state of node, bitmask as visited
            visited.add((node, mask))

        while queue:
            state: List[int]=queue.popleft()

            current_node: int=state[0]

            current_mask: int=state[1]

            current_path_length: int=state[2]

            #If the current bitmask matches that of the bitmask representing the state where all nodes in the graph have been visited,
            #we know that the current path length will be the shortest due to the nature of breadth-first search
            if current_mask==all_visited:
                result=current_path_length

                break

            #Iterate through all neighbours of the current node in the graph
            for neighbour in graph[current_node]:
                #Bitmask where the bit in the neighbour node-th position from the left is set
                #to 1 indicating that we have visited this neighbour node in our path
                neighbour_mask: int=(1 << neighbour)

                #Calculate the new bitmask representing the update state of our path
                next_mask: int=(current_mask | neighbour_mask)

                #If the current tuple of neighbour and next_mask has not been seen before
                #IMPORTANT: we use a tuple of node, bitmask represent the state since we are
                #allowed to revisit nodes and reuse edges multiple times. If we just used the
                #bitmask by itself, that would only allow us to visit a node and traverse an edge once
                if (neighbour, next_mask) not in visited:
                    #Add it to the visited set
                    visited.add((neighbour, next_mask))

                    #Enqueue the next state
                    queue.append([neighbour, next_mask, current_path_length + 1])

        return result
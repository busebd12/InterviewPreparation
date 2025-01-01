'''
Resources used:

1) Video on minimum spanning trees: https://www.youtube.com/watch?v=4ZlRH0eK-qQ

2) Example solution: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/solutions/3929059/beats-100-js-ts-java-c-c-python-python3-kotlin/
'''
class UnionFind:
    def __init__(self, n: int):
        self.parent=[vertex for vertex in range(0, n)]
    
    def find(self, vertex: int) -> int:
        if self.parent[vertex]==vertex:
            return vertex

        self.parent[vertex]=self.find(self.parent[vertex])

        return self.parent[vertex]

    def union(self, u: int, v: int) -> None:
        u_parent=self.find(u)

        v_parent=self.find(v)

        self.parent[u_parent]=v_parent
            

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        result: List[List[int]]=list()

        e: int=len(edges)

        #For each edge, add the index to the end so that we know the original ordering of the
        #edges after we sort the edges since sorting could cause the ordering to be different
        for index in range(0, e):
            edges[index].append(index)

        #Sort the edges based on weight
        edges.sort(key=lambda edge: edge[2])

        #Find the cost of the minimum spanning tree
        original_minimum_spanning_tree_cost: int=self.find_minimum_spanning_tree_cost(edges, n, e, -1, -1)

        critical_edges: List[int]=list()

        pseudo_critical_edges: List[int]=list()

        #For each edge
        for index in range(0, e):

            cost_with_including_edge: int=self.find_minimum_spanning_tree_cost(edges, n, e, index, -1)

            cost_with_excluding_edge: int=self.find_minimum_spanning_tree_cost(edges, n, e, -1, index)

            #If the cost of the minimum spanning tree when excluding the current edge is greater
            #than the original minimum spanning tree cost, we know that this is a critical edge
            if cost_with_excluding_edge > original_minimum_spanning_tree_cost:
                #IMPORTANT: we add edges[index][3] instead of index since edges[index][3] is the edge's index in the original ordering before we sorted
                critical_edges.append(edges[index][3])

            #Else if the cost of the minimum spanning tree when including the current edge is equal
            #to the original minimum spanning tree cost, we know that this is a pseudo-critical edge
            elif cost_with_including_edge==original_minimum_spanning_tree_cost:
                #IMPORTANT: we add edges[index][3] instead of index since edges[index][3] is the edge's index in the original ordering before we sorted
                pseudo_critical_edges.append(edges[index][3])

        result.append(critical_edges)

        result.append(pseudo_critical_edges)

        return result

    def find_minimum_spanning_tree_cost(self, edges: List[List[int]], n: int, e: int, included_edge: int, excluded_edge: int) -> int:
        union_find: UnionFind=UnionFind(n)

        cost: int=0

        #If the included edge is a valid edge
        if included_edge!=-1:
            #Add the weight of the edge to cost of the minimum spanning tree
            cost+=edges[included_edge][2]
            #Union the disjoint sets of the two vertices
            union_find.union(edges[included_edge][0], edges[included_edge][1])

        for index in range(0, e):
            u: int=edges[index][0]

            v: int=edges[index][1]

            weight: int=edges[index][2]

            #If the index of the current edge is index of the excluded edge, skip it
            if index==excluded_edge:
                continue

            u_parent=union_find.find(u)

            v_parent=union_find.find(v)

            #If the parent of the u vertex is the same as the parent of the v vertex, then these two vertices are already connected by an edge
            #Connecting them by another edge would create a cycle and we don't want that since trees are acyclic, so skip this edge
            if u_parent==v_parent:
                continue

            #No cycle would be formed so union the disjoint sets of the two vertices
            union_find.union(u, v)

            #Add the weight of the edge to the cost
            cost+=weight

        #For each vertex
        for vertex in range(0, n):
            #If the parent of the vertex is not the same the parent of vertex zero,
            #then we know these two vertices are not part of the same connected component,
            #so this minimum spanning tree is not valid since all vertices have to be part of the same connected component
            if union_find.find(vertex)!=union_find.find(0):
                return float('inf')

        return cost
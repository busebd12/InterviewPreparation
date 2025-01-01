'''
Solution is based on this explanation: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/1240498/java-topological-sorting-with-explanation/
'''
class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        result: List[int]=list()

        total_number_of_groups=self.get_total_number_of_groups(group)

        current_max_group_number: int=max(group)

        #Since items that belong to group -1 don't formally belong to a group,
        #we assign each of those items its own unique, valid group number start from the maximum valid group number from group plus 1
        special_group_number: int=current_max_group_number + 1

        #Create a mapping of item to the group it belongs to
        item_to_group_graph: List[int]=self.build_item_to_group_graph(group, special_group_number, n)

        #Build the graph representing the dependencies described by beforeItems
        dependency_graph: List[List[int]]=self.build_dependency_graph(beforeItems, n)

        #Calculate the indegree of each item: how many items should come before the each item
        item_indegree: List[int]=self.build_item_indegree(beforeItems, n)

        #Create a graph of the form {group --> [list of groups]} that maps each group to a list of groups based on the following criteria:
        #all items in "group" must come before all items in each group in [list of groups] in the sorted order
        group_to_groups_graph: List[List[int]]=self.build_group_to_groups_graph(beforeItems, item_to_group_graph, n, total_number_of_groups)

        #Calculate the group indegree: how many groups must come before the current group in the sorted ordering
        group_indegree: int=self.build_group_indegree(beforeItems, item_to_group_graph, n, total_number_of_groups)

        #Sort the groups topologically
        group_topological_order: List[int]=self.get_groups_topological_order(group_to_groups_graph, group_indegree, total_number_of_groups)

        #Sort the items topologically
        item_topological_order: List[int]=self.get_item_topological_order(dependency_graph,item_indegree, n)

        #If a topological ordering of the groups or items is not possible, then no sorted ordering can be found
        if not group_topological_order or not item_topological_order:
            return []

        #Build a mapping of each group to the items in that group sorted topologically
        group_to_ordered_items: List[List[int]]=self.build_group_to_ordered_items(item_to_group_graph, item_topological_order, total_number_of_groups)

        #For each group in topological order
        for _group in group_topological_order:
            #If there are items in this group
            if group_to_ordered_items[_group]:
                #For each topologically ordered item in this group
                for item in group_to_ordered_items[_group]:
                    #Append the item to the result
                    result.append(item)

        return result
    
    def get_total_number_of_groups(self, group: List[int]) -> int:
        total_groups: int=0

        current_largest_group: int=max(group)

        negative_ones: int=0

        for group_number in group:
            if group_number < 0:
                negative_ones+=1

        max_group_number_zero_based: int=current_largest_group + negative_ones

        total_groups=max_group_number_zero_based + 1

        return total_groups

    def build_item_to_group_graph(self, group: List[int], special_group_value: int, n: int) -> List[int]:
        item_to_group: List[int]=[-1] * n

        for item in range(0, n):
            if group[item]==-1:
                item_to_group[item]=special_group_value
                
                special_group_value+=1
            else:
                item_to_group[item]=group[item]

        return item_to_group

    def build_dependency_graph(self, beforeItems: List[List[int]], n: int) -> List[List[int]]:
        dependency_graph: List[List[int]]=[list() for iteration in range(0, n)]

        for item in range(0, n):
            if beforeItems[item]:
                for before_item in beforeItems[item]:
                    dependency_graph[before_item].append(item)

        return dependency_graph

    def build_item_indegree(self, beforeItems: List[List[int]], n: int) -> List[int]:
        item_indegree: List[int]=[0] * n

        for item in range(0, n):
            if beforeItems[item]:
                for before_item in beforeItems[item]:
                    item_indegree[item]+=1

        return item_indegree

    def build_group_to_groups_graph(self, beforeItems: List[List[int]], item_to_group_graph: List[int], n: int, total_number_of_groups: int) -> List[List[int]]:
        group_to_groups_graph: List[List[int]]=[list() for iteration in range(0, total_number_of_groups + 1)]

        for item in range(0, n):
            if beforeItems[item]:
                after: int=item

                after_group: int=item_to_group_graph[after]

                for before in beforeItems[item]:
                    before_group: int=item_to_group_graph[before]

                    #Only if the group of the item that comes before is different than the group of
                    #the item that comes after do we create the mapping of before_group to after_group
                    #This way, we don't create a cycle between two that belong to the same group but one item comes before another item in the sorted order
                    if before_group!=after_group:
                        group_to_groups_graph[before_group].append(after_group)

        return group_to_groups_graph

    def build_group_indegree(self, beforeItems: List[List[int]], item_to_group_graph: List[int], n: int, total_number_of_groups: int) -> List[int]:
        group_indegree: List[int]=[0] * (total_number_of_groups + 1)

        for item in range(0, n):
            if beforeItems[item]:
                after: int=item

                after_group: int=item_to_group_graph[after]

                for before in beforeItems[item]:
                    before_group: int=item_to_group_graph[before]

                    if before_group!=after_group:
                        group_indegree[after_group]+=1

        return group_indegree

    def get_item_topological_order(self, dependency_graph: List[List[int]], item_indegree: List[int], n: int) -> List[int]:
        return self.topological_sort(dependency_graph, item_indegree, n)

    def get_groups_topological_order(self, group_to_groups_graph: List[List[int]], group_indegree: List[int], total_number_of_groups: int) -> List[int]:

        return self.topological_sort(group_to_groups_graph, group_indegree, total_number_of_groups)

    def topological_sort(self, graph: List[List[int]], indegree: List[int], vertices: int) -> List[int]:
        ordering: List[int]=list()

        queue: Deque[int]=deque()

        for vertex in range(0, vertices):
            if indegree[vertex]==0:
                queue.append(vertex)

        while queue:
            vertex: int=queue.popleft()

            ordering.append(vertex)

            if graph[vertex]:
                for neighbour in graph[vertex]:
                    indegree[neighbour]-=1

                    if indegree[neighbour]==0:
                        queue.append(neighbour)

        if len(ordering)!=vertices:
            return []

        return ordering

    def build_group_to_ordered_items(self, item_to_group_graph: List[int], item_topological_order: List[int], total_number_of_groups: int) -> List[List[int]]:
        group_to_ordered_items: List[List[int]]=[list() for iteration in range(0, total_number_of_groups + 1)]

        for item in item_topological_order:
            group: int=item_to_group_graph[item]

            group_to_ordered_items[group].append(item)

        return group_to_ordered_items
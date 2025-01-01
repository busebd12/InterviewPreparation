class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        result: int=0

        n: int=len(nuts)

        distance_from_squirrel_to_nut: List[int]=self.get_distance_from_squirrel_to_nuts_array(nuts, n, squirrel)

        distance_from_nut_to_tree: List[int]=self.get_distance_from_nuts_to_tree_array(nuts, n, tree)

        total_distance_collecting_nuts_starting_from_tree: int=0

        for index in range(0, n):
            round_trip: int=2 * distance_from_nut_to_tree[index]

            total_distance_collecting_nuts_starting_from_tree+=round_trip

        result: int=(2**53) - 1

        for index in range(0, n):
            squirrel_to_nut_distance: int=distance_from_squirrel_to_nut[index]

            nut_to_tree_distance: int=distance_from_nut_to_tree[index]

            remaining: int=total_distance_collecting_nuts_starting_from_tree - nut_to_tree_distance + squirrel_to_nut_distance

            result=min(result, remaining)

        return result

    def get_distance_from_squirrel_to_nuts_array(self, nuts: List[List[int]], n: int, squirrel: List[int]) -> List[int]:
        distance_from_squirrel_to_nut: List[int]=[0 for _ in range(0, n)]

        for index in range(0, n):
            nut: List[int]=nuts[index]

            distance: int=self.get_manhattan_distance(nut, squirrel)

            distance_from_squirrel_to_nut[index]=distance

        return distance_from_squirrel_to_nut

    def get_distance_from_nuts_to_tree_array(self, nuts: List[List[int]], n: int, tree: List[int]) -> List[int]:
        distance_from_nut_to_tree: List[int]=[0 for _ in range(0, n)]

        for index in range(0, n):
            nut: List[int]=nuts[index]

            distance: int=self.get_manhattan_distance(nut, tree)

            distance_from_nut_to_tree[index]=distance

        return distance_from_nut_to_tree

    def get_manhattan_distance(self, point1: List[int], point2: List[int]) -> int:
        x1: int=point1[0]

        y1: int=point1[1]

        x2: int=point2[0]

        y2: int=point2[1]

        return abs(x1 - x2) + abs(y1 - y2)
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited=set()

        visited.add((0, 0))

        current_x=0

        current_y=0

        for direction in path:
            if direction=='N':
                current_x-=1
            elif direction=='S':
                current_x+=1
            elif direction=='E':
                current_y+=1
            else:
                current_y-=1
            
            next_point=(current_x, current_y)

            if next_point in visited:
                return True
            
            visited.add(next_point)

        return False
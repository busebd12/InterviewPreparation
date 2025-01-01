class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        moves_along_x_axis: int=abs(fx - sx)

        moves_along_y_axis: int=abs(fy - sy)

        min_moves_to_reach_destination: int=0

        if moves_along_x_axis <= moves_along_y_axis:
            min_moves_to_reach_destination+=(moves_along_x_axis + (moves_along_y_axis - moves_along_x_axis))
        else:
            min_moves_to_reach_destination+=(moves_along_y_axis + (moves_along_x_axis - moves_along_y_axis))

        if sx==fx and sy==fy:
            return t!=1

        return t >= min_moves_to_reach_destination
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        
        #If the length of s and goal are not the same, then no amount of swapping will make them equal
        if len(s)!=len(goal):
            return False

        n: int=len(s)

        if s==goal:
           unordered_set: set(chr)=set(s)

           #If the number of unique characters in s is less than the length of s, then there is at least one extra character that
           #can be swapped with another character in s to ensure that s is the same as goal
           if len(unordered_set) < n:
               return True
           else:
               return False
        
        indices: List[int]=self.get_indices_where_strings_differ(s, goal)

        #There can only be exactly two indices where s and goal are different
        if len(indices)!=2:
            return False

        i: int=indices[0]

        j: int=indices[1]

        #If swapping either pair of letters doesn't make s and goal the same
        if s[i]!=goal[j] or s[j]!=goal[i]:
            return False

        return True

    def get_indices_where_strings_differ(self, s: str, goal: str) -> List[int]:
        indices: List[int]=list()

        n: int=len(s)

        for index in range(0, n):
            if s[index]!=goal[index]:
                indices.append(index)

        return indices
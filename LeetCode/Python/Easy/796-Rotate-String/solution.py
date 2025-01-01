class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s)!=len(goal):
            return False
        
        combined: str=s + s

        return combined.find(goal)!=-1
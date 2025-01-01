class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack: List[chr]=self.process_string(s)

        t_stack: List[chr]=self.process_string(t)

        return s_stack==t_stack

    def process_string(self, string: str) -> List[chr]:
        stack: List[chr]=list()

        for character in string:
            if character=='#':
                if stack:
                    stack.pop()
            else:
                stack.append(character)

        return stack

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        n: int=len(s)

        m: int=len(t)

        s_index: int=n-1

        t_index: int=m-1

        s_backspaces: int=0

        t_backspaces: int=0

        while s_index >= 0 or t_index >= 0:
            while s_index >= 0:
                if s[s_index]=='#':
                    s_backspaces+=1

                    s_index-=1
                elif s_backspaces > 0:
                    s_index-=1

                    s_backspaces-=1
                else:
                    break

            while t_index >= 0:
                if t[t_index]=='#':
                    t_backspaces+=1

                    t_index-=1
                elif t_backspaces > 0:
                    t_index-=1

                    t_backspaces-=1
                else:
                    break

            if s_index >= 0 and t_index >= 0 and s[s_index]!=t[t_index]:
                return False

            if (s_index < 0 and t_index >= 0) or (s_index >= 0 and t_index < 0):
                return False

            s_index-=1

            t_index-=1

        return True
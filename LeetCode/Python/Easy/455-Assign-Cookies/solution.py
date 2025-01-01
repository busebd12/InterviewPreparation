class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        result=0

        if not s:
            return result

        g=sorted(g)

        n=len(g)

        s=sorted(s)

        m=len(s)

        visited=[False for _ in range(0, m)]

        for greed in g:
            for (index, cookie) in enumerate(s):
                if not visited[index] and s[index] >= greed:
                    result+=1

                    visited[index]=True

                    break

        return result

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        result=0

        if not s:
            return result

        g.sort()

        s.sort()

        n=len(g)

        m=len(s)

        greed_index=0

        cookie_index=0

        while greed_index < n and cookie_index < m:
            if g[greed_index] <= s[cookie_index]:
                result+=1

                greed_index+=1
            
            cookie_index+=1

        return result
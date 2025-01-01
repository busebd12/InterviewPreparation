class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        result: int=-1

        if len(trust)==0:
            return n if n==1 else -1

        indegree: list[int]=[0] * (n + 1)

        outdegree: list[int]=[0] * (n + 1)

        for edge in trust:
            a: int=edge[0]

            b: int=edge[1]

            outdegree[a]+=1

            indegree[b]+=1

        for person in range(1, n + 1):
            if indegree[person]==n-1 and outdegree[person]==0:
                result=person

                break

        return result
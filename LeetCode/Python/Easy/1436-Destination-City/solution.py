class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        result=""

        outdegree=dict()

        for path in paths:
            outgoing=path[0]

            incoming=path[1]

            if outgoing not in outdegree.keys():
                outdegree[outgoing]=0

            if incoming not in outdegree.keys():
                outdegree[incoming]=0

        for path in paths:
            outgoing=path[0]

            outdegree[outgoing]+=1

        for path in paths:
            incoming=path[1]

            if outdegree[incoming]==0:
                result=incoming

                break

        return result
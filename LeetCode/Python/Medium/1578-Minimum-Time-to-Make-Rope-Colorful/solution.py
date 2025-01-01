class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        result=0

        n=len(colors)

        i=0

        while i < n:
            running_sum=neededTime[i]

            max_time=neededTime[i]

            count=1

            j=i + 1

            while j < n and colors[i]==colors[j]:
                count+=1

                running_sum+=neededTime[j]

                max_time=max(max_time, neededTime[j])

                j+=1
            
            if count > 1:
                running_sum-=max_time

                result+=running_sum

            i=j

        return result
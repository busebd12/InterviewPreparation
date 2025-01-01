class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        result: List[str]=list()

        t: int=len(target)

        index: int=0

        stack: List[int]=list()

        for number in range(1, n + 1):
            if index==t:
                break
            
            if stack:
                previous: int=index - 1

                if previous < 0:
                    previous+=1

                if stack[-1]!=target[previous]:
                    stack.pop()

                    result.append("Pop")

            stack.append(number)

            result.append("Push")

            if number==target[index]:
                index+=1

        return result
from collections import deque

class Solution:
    def simplifyPath(self, path: str) -> str:
        result=""

        parts=path.split('/')

        stack=list()

        for part in parts:
            if part=="." or not part:
                continue
            elif part=="..":
                if stack:
                    stack.pop()
            else:
                stack.append(part)

        simplified_path_parts=["/"]

        stack.reverse()

        while stack:
            part=stack.pop()

            simplified_path_parts.append(part)

            if stack:
                simplified_path_parts.append("/")

        result="".join(simplified_path_parts)

        return result

class Solution:
    def simplifyPath(self, path: str) -> str:
        result=""

        parts=path.split('/')

        stack=deque()

        for part in parts:
            if part=="." or not part:
                continue
            elif part=="..":
                if stack:
                    stack.pop()
            else:
                stack.append(part)

        simplified_path_parts=["/"]

        while stack:
            part=stack.popleft()

            simplified_path_parts.append(part)

            if stack:
                simplified_path_parts.append("/")

        result="".join(simplified_path_parts)

        return result
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.queue=deque()

        self.flatten(nestedList)

    def flatten(self, nestedList: [NestedInteger]):
        stack: List[NestedInteger]=list()

        for item in nestedList:
            stack.append(item)

        while stack:
            current: [NestedInteger]=stack.pop()

            if current.isInteger():
                self.queue.appendleft(current.getInteger())
            else:
                for element in current.getList():
                    stack.append(element)        
    
    def next(self) -> int:
        return self.queue.popleft()
    
    def hasNext(self) -> bool:
        return len(self.queue) > 0
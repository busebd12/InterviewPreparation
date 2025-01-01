class MyHashSet:
    def __init__(self):
        self.max_size: int=(10**6) + 1

        self.hashset: List[bool]=[False for _ in range(0, self.max_size)]
        
    def add(self, key: int) -> None:
        self.hashset[key]=True
        
    def remove(self, key: int) -> None:
        self.hashset[key]=False

    def contains(self, key: int) -> bool:
        return self.hashset[key]